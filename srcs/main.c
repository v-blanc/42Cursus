/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 17:20:01 by vblanc            #+#    #+#             */
/*   Updated: 2025/02/05 00:06:57 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

typedef struct s_data
{
	void	*img;
	void	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}			t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	int	*dst;

	dst = data->addr;
	dst[(y * data->line_length / 4) + x] = color;
}

void	ft_temp(t_data img, int x, int y)
{
	int		max_iter;
	int		i;
	double	x_tmp;
	double	zx;
	double	zy;
	double	cx;
	double	cy;
	double	zoom;
	double	offset_x;
	double	offset_y;

	zoom = 200;
	offset_x = -2.3;
	offset_y = -1.2;
	zx = 0.0;
	zy = 0.0;
	cx = (x / zoom) + offset_x;
	cy = (y / zoom) + offset_y;
	max_iter = 50;
	i = 0;
	while (i < max_iter)
	{
		x_tmp = zx * zx - zy * zy + cx;
		zy = 2 * zx * zy + cy;
		zx = x_tmp;
		if (zx * zx + zy * zy > __DBL_MAX__)
			break ;
		i++;
	}
	// printf("x: %d, y: %d, i: %d\n", x, y, i);
	if (i == max_iter)
		my_mlx_pixel_put(&img, x, y, 0x000000);
	else
		my_mlx_pixel_put(&img, x, y, 0xFCBE11 * i);
}

void	ft_printf_fractal(t_data img)
{
	int	x;
	int	y;

	x = 0;
	while (x < WINDOW_HEIGHT)
	{
		y = 0;
		while (y < WINDOW_WIDTH)
		{
			ft_temp(img, x, y);
			y++;
		}
		x++;
	}
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, WINDOW_HEIGHT, WINDOW_WIDTH, "fract-ol");
	img.img = mlx_new_image(mlx, WINDOW_HEIGHT, WINDOW_WIDTH);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_length,
			&img.endian);
	ft_printf_fractal(img);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
