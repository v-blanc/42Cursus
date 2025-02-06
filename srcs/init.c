/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 03:12:51 by vblanc            #+#    #+#             */
/*   Updated: 2025/02/06 20:52:57 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

void	init_mlx(t_fractal *fractal)
{
	fractal->mlx = mlx_init();
	if (!fractal->mlx)
		exit(1);
	fractal->mlx_win = mlx_new_window(fractal->mlx, WINDOW_HEIGHT, WINDOW_WIDTH,
			"fract-ol");
	fractal->img = mlx_new_image(fractal->mlx, WINDOW_HEIGHT, WINDOW_WIDTH);
	fractal->addr = (int *)mlx_get_data_addr(fractal->img, &fractal->bpp,
			&fractal->line_length, &fractal->endian);
	mlx_do_key_autorepeaton(fractal->mlx);
}

void	init_fractal_name(t_fractal *fractal, char **input)
{
	if (!ft_strncmp(input[0], "mandelbrot", ft_strlen(input[0])))
		fractal->name = 'm';
	else if (!ft_strncmp(input[0], "julia", ft_strlen(input[0])))
	{
		fractal->name = 'j';
		if (input[1])
		{
			fractal->cx = ft_atof(input[1]);
			fractal->cy = ft_atof(input[2]);
		}
		else
		{
			fractal->cx = -0.8;
			fractal->cy = 0.156;
		}
	}
	else if (!ft_strncmp(input[0], "lotus", ft_strlen(input[0])))
		fractal->name = 'l';
}

void	init_fractal_window(t_fractal *fractal)
{
	if (fractal->name == 'm')
	{
		fractal->zoom = 430;
		fractal->offset_x = -2.80;
		fractal->offset_y = -1.2;
		fractal->max_iter = 50;
	}
	else if (fractal->name == 'j')
	{
		fractal->zoom = 560;
		fractal->offset_x = -1.7;
		fractal->offset_y = -0.9;
		fractal->max_iter = 50;
	}
	else if (fractal->name == 'l')
	{
		fractal->zoom = 370;
		fractal->offset_x = -2.55;
		fractal->offset_y = -1.35;
		fractal->max_iter = 50;
	}
	fractal->inv_zoom = 1.0 / fractal->zoom;
	fractal->color_index = 0;
}

void	init_fractal_colors(t_fractal *fractal)
{
	fractal->colors = ft_calloc(sizeof(int), COLOR_NUMBER);
	if (!fractal->colors)
		return ;
	fractal->colors[0] = 0xE0E1DD;
	fractal->colors[1] = 0xE3DFDF;
	fractal->colors[2] = 0xDCE0E1;
	fractal->colors[3] = 0xECECEC;
	fractal->colors[4] = 0xF00E0A;
}
