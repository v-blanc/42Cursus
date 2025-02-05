/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 03:23:03 by vblanc            #+#    #+#             */
/*   Updated: 2025/02/05 14:17:32 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

static void	my_mlx_pixel_put(t_fractal *fractal, int x, int y, int color)
{
	int	*dst;

	dst = fractal->addr;
	dst[(y * fractal->line_length >> 2) + x] = color;
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

static void	calculate_sequence(t_fractal *fractal)
{
	double	x_tmp;

	if (fractal->name == 'm' || fractal->name == 'j')
	{
		x_tmp = fractal->zx * fractal->zx - fractal->zy * fractal->zy
			+ fractal->cx;
		fractal->zy = 2 * fractal->zx * fractal->zy + fractal->cy;
		fractal->zx = x_tmp;
	}
	if (fractal->name == 't')
	{
		x_tmp = fractal->zx * fractal->zx - fractal->zy * fractal->zy
			+ fractal->cx;
		fractal->zy = -2 * fractal->zx * fractal->zy + fractal->cy;
		fractal->zx = x_tmp;
	}
}

static void	sub_draw_fractal(t_fractal *fractal, int x, int y)
{
	int	i;

	init_fractal_values(fractal, x, y);
	i = 0;
	while (i < fractal->max_iter && fractal->zx * fractal->zx + fractal->zy
		* fractal->zy < 4)
	{
		calculate_sequence(fractal);
		i++;
	}
	if (i == fractal->max_iter)
		my_mlx_pixel_put(fractal, x, y, 0x000000);
	else
		my_mlx_pixel_put(fractal, x, y, 0xE0E1DD * i);
	// my_mlx_pixel_put(fractal, x, y, 0xE0E1DD * (i % 16));
}

void	draw_fractal(t_fractal *fractal)
{
	int		x;
	int		y;
	clock_t	start;
	clock_t	end;

	start = clock();
	mlx_new_image(fractal->mlx, WINDOW_HEIGHT, WINDOW_WIDTH);
	x = 0;
	while (x < WINDOW_HEIGHT)
	{
		y = 0;
		while (y < WINDOW_WIDTH)
		{
			sub_draw_fractal(fractal, x, y);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(fractal->mlx, fractal->mlx_win, fractal->img, 0, 0);
	end = clock();
	printf("Time: %f\n", (double)(end - start) / CLOCKS_PER_SEC);
}
