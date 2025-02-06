/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 04:27:46 by vblanc            #+#    #+#             */
/*   Updated: 2025/02/06 20:41:13 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

void	print_border(t_fractal *fractal)
{
	int	i;
	int	j;
	int	crd;

	i = 80;
	while (i < 300)
	{
		j = 30;
		while (j < 210)
		{
			crd = (j * fractal->line_length >> 2) + i;
			if (j == 30 || j == 60 || j == 90 || j == 120 || j == 150
				|| j == 180 || j == 209 || i == 80 || i == 299)
				fractal->addr[crd] = 0x000000;
			j++;
		}
		i++;
	}
}

void	print_rectangle(t_fractal *fractal)
{
	int	i;
	int	j;
	int	crd;

	i = 80;
	while (i < 300)
	{
		j = 30;
		while (j < 210)
		{
			crd = (j * fractal->line_length >> 2) + i;
			fractal->addr[crd] = blend_colors(0x7f7f7f, fractal->addr[crd],
					0.9);
			j++;
		}
		i++;
	}
	print_border(fractal);
	mlx_put_image_to_window(fractal->mlx, fractal->mlx_win, fractal->img, 0, 0);
}

static void	print_double_info(t_fractal *fractal, char *str, double value,
		int pos)
{
	char	*tmp;

	if (!ft_strncmp(str, "Max iter:", ft_strlen(str)) || !ft_strncmp(str,
			"Zoom:", ft_strlen(str)))
		tmp = ft_itoa((int)value);
	else
		tmp = ft_dtoa_2f(value);
	mlx_string_put(fractal->mlx, fractal->mlx_win, 100, pos, 0x000000, str);
	if (tmp)
		mlx_string_put(fractal->mlx, fractal->mlx_win, 190, pos, 0x000000, tmp);
	free(tmp);
}

static void	print_threads_info(t_fractal *fractal)
{
	mlx_string_put(fractal->mlx, fractal->mlx_win, 100, 200, 0x000000,
		"Multithreading:");
	if (fractal->mthreads_flag == 0)
		mlx_string_put(fractal->mlx, fractal->mlx_win, 240, 200, 0x000000,
			"no");
	else
		mlx_string_put(fractal->mlx, fractal->mlx_win, 240, 200, 0x000000,
			"yes");
}

void	put_image(t_fractal *fractal)
{
	print_rectangle(fractal);
	mlx_set_font(fractal->mlx, fractal->mlx_win, "9x15bold");
	mlx_string_put(fractal->mlx, fractal->mlx_win, 100, 50, 0x000000,
		"Fractal:");
	if (fractal->name == 'm')
		mlx_string_put(fractal->mlx, fractal->mlx_win, 190, 50, 0x000000,
			"mandelbrot");
	else if (fractal->name == 'j')
		mlx_string_put(fractal->mlx, fractal->mlx_win, 190, 50, 0x000000,
			"julia");
	else if (fractal->name == 'l')
		mlx_string_put(fractal->mlx, fractal->mlx_win, 190, 50, 0x000000,
			"lotus");
	print_double_info(fractal, "Max iter:", fractal->max_iter, 80);
	print_double_info(fractal, "Zoom:", fractal->zoom, 110);
	print_double_info(fractal, "x offset:", fractal->offset_x, 140);
	print_double_info(fractal, "y offset:", fractal->offset_y, 170);
	print_threads_info(fractal);
}
