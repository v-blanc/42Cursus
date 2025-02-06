/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_multithreads.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 22:37:49 by vblanc            #+#    #+#             */
/*   Updated: 2025/02/06 04:28:38 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

static void	my_mlx_pixel_put(t_fractal *fractal, int x, int y, int color)
{
	fractal->addr[(y * fractal->line_length >> 2) + x] = color;
}

static void	init_fractal_values(t_fractal *fractal, int x, int y)
{
	if (fractal->name == 'm')
	{
		fractal->zx = 0.0;
		fractal->zy = 0.0;
		fractal->cx = (x * fractal->inv_zoom) + fractal->offset_x;
		fractal->cy = (y * fractal->inv_zoom) + fractal->offset_y;
	}
	else if (fractal->name == 'j')
	{
		fractal->zx = (x * fractal->inv_zoom) + fractal->offset_x;
		fractal->zy = (y * fractal->inv_zoom) + fractal->offset_y;
	}
	else if (fractal->name == 't')
	{
		fractal->zx = 0.0;
		fractal->zy = 0.0;
		fractal->cx = (x * fractal->inv_zoom) + fractal->offset_x;
		fractal->cy = (y * fractal->inv_zoom) + fractal->offset_y;
	}
}

static void	calculate_sequence(t_fractal *fractal, double zx_2, double zy_2)
{
	double	x_tmp;

	if (fractal->name == 'm' || fractal->name == 'j')
	{
		x_tmp = zx_2 - zy_2 + fractal->cx;
		fractal->zy = 2 * fractal->zx * fractal->zy + fractal->cy;
		fractal->zx = x_tmp;
	}
	if (fractal->name == 't')
	{
		x_tmp = zx_2 - zy_2 + fractal->cx;
		fractal->zy = -2 * fractal->zx * fractal->zy + fractal->cy;
		fractal->zx = x_tmp;
	}
}

static void	sub_draw_fractal(t_fractal *fractal, int x, int y)
{
	double	zx_2;
	double	zy_2;
	int		i;

	init_fractal_values(fractal, x, y);
	zx_2 = fractal->zx * fractal->zx;
	zy_2 = fractal->zy * fractal->zy;
	i = 0;
	while (i < fractal->max_iter && zx_2 + zy_2 < 4)
	{
		calculate_sequence(fractal, zx_2, zy_2);
		zx_2 = fractal->zx * fractal->zx;
		zy_2 = fractal->zy * fractal->zy;
		i++;
	}
	if (i == fractal->max_iter)
		my_mlx_pixel_put(fractal, x, y, 0x000000);
	else
		my_mlx_pixel_put(fractal, x, y, 0xE0E1DD * i);
	// my_mlx_pixel_put(fractal, x, y, 0xE0E1DD * (i % 16));
}

/* ************************************************************************** */
/* ****************************    NEW    *********************************** */
/* ************************************************************************** */

typedef struct s_thread_data
{
	t_fractal	*fractal;
	int			start_line;
	int			end_line;
}				t_thread_data;

void	*draw_fractal_thread(void *arg)
{
	t_thread_data	*data;
	t_fractal		local_fractal;
	int				x;
	int				y;

	data = (t_thread_data *)arg;
	x = data->start_line;
	while (x < data->end_line)
	{
		y = 0;
		while (y < WINDOW_WIDTH)
		{
			local_fractal = *(data->fractal);
			sub_draw_fractal(&local_fractal, x, y);
			y++;
		}
		x++;
	}
	return (NULL);
}

void	draw_fractal(t_fractal *fractal)
{
	pthread_t		threads[THREADS];
	t_thread_data	thread_data[THREADS];
	int				lines_per_thread;
	int				i;

	lines_per_thread = WINDOW_HEIGHT / THREADS;
	fractal->img = mlx_new_image(fractal->mlx, WINDOW_HEIGHT, WINDOW_WIDTH);
	fractal->addr = (int *)mlx_get_data_addr(fractal->img, &fractal->bpp,
			&fractal->line_length, &fractal->endian);
	for (i = 0; i < THREADS; i++)
		threads[i] = 0;
	for (i = 0; i < THREADS; i++)
	{
		thread_data[i].fractal = fractal;
		thread_data[i].start_line = i * lines_per_thread;
		if (i == THREADS - 1)
			thread_data[i].end_line = WINDOW_HEIGHT;
		else
			thread_data[i].end_line = (i + 1) * lines_per_thread;
		pthread_create(&threads[i], NULL, draw_fractal_thread, &thread_data[i]);
	}
	for (i = 0; i < THREADS; i++)
		pthread_join(threads[i], NULL);
	print_info(fractal);
}
