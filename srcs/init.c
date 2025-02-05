/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 03:12:51 by vblanc            #+#    #+#             */
/*   Updated: 2025/02/05 08:23:00 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

void	init_mlx(t_fractal *fractal)
{
	fractal->mlx = mlx_init();
	fractal->mlx_win = mlx_new_window(fractal->mlx, WINDOW_HEIGHT, WINDOW_WIDTH,
			"fract-ol");
	fractal->img = mlx_new_image(fractal->mlx, WINDOW_HEIGHT, WINDOW_WIDTH);
	fractal->addr = mlx_get_data_addr(fractal->img, &fractal->bpp,
			&fractal->line_length, &fractal->endian);
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
			// TODO : create ft_atof in libft
			fractal->cx = atof(input[1]);
			fractal->cy = atof(input[2]);
		}
		else
		{
			fractal->cx = -0.8;
			fractal->cy = 0.156;
		}
	}
	else if (!ft_strncmp(input[0], "tricorn", ft_strlen(input[0])))
		fractal->name = 't';
}

void	init_fractal_window(t_fractal *fractal)
{
	if (fractal->name == 'm')
	{
		fractal->zoom = 200;
		fractal->offset_x = -2.35;
		fractal->offset_y = -1.2;
		fractal->max_iter = 100;
	}
	else if (fractal->name == 'j')
	{
		fractal->zoom = 180;
		fractal->offset_x = -1.95;
		fractal->offset_y = -1.3;
		fractal->max_iter = 100;
	}
	else if (fractal->name == 't')
	{
		fractal->zoom = 150;
		fractal->offset_x = -2.6;
		fractal->offset_y = -1.6;
		fractal->max_iter = 100;
	}
}
