/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 03:23:03 by vblanc            #+#    #+#             */
/*   Updated: 2025/03/03 14:33:36 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol_bonus.h"

void	my_mlx_pixel_put(t_fractal *fractal, int x, int y, int color)
{
	fractal->addr[(y * fractal->line_length >> 2) + x] = color;
}

void	init_fractal_values(t_fractal *fractal, int x, int y)
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
	else if (fractal->name == 'l')
	{
		fractal->zx = (x * fractal->inv_zoom) + fractal->offset_x;
		fractal->zy = (y * fractal->inv_zoom) + fractal->offset_y;
		fractal->cx = 0.1;
		fractal->cy = 0.65;
	}
}

void	sub_draw_fractal(t_fractal *fractal, int x, int y)
{
	double	zx_2;
	double	zy_2;
	int		i;
	double	x_tmp;

	init_fractal_values(fractal, x, y);
	zx_2 = fractal->zx * fractal->zx;
	zy_2 = fractal->zy * fractal->zy;
	i = 0;
	while (i < fractal->max_iter && zx_2 + zy_2 < 4)
	{
		x_tmp = zx_2 - zy_2 + fractal->cx;
		fractal->zy = 2 * fractal->zx * fractal->zy + fractal->cy;
		fractal->zx = x_tmp;
		zx_2 = fractal->zx * fractal->zx;
		zy_2 = fractal->zy * fractal->zy;
		i++;
	}
	if (i == fractal->max_iter)
		my_mlx_pixel_put(fractal, x, y, 0x000000);
	else
		my_mlx_pixel_put(fractal, x, y, fractal->colors[fractal->color_index]
			* (i % 16));
}

void	draw_fractal(t_fractal *fractal)
{
	int	x;
	int	y;

	if (fractal->mthreads_flag == 1)
	{
		draw_fractal_threads(fractal);
		return ;
	}
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
	put_image(fractal);
}
