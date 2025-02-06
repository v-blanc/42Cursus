/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 04:27:46 by vblanc            #+#    #+#             */
/*   Updated: 2025/02/06 09:07:26 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

static int	blend_colors(int fg_hex, int bg_hex, double alpha)
{
	int	r;
	int	g;
	int	b;

	r = ((fg_hex >> 16) & 0xFF) * alpha + ((bg_hex >> 16) & 0xFF) * (1 - alpha);
	g = ((fg_hex >> 8) & 0xFF) * alpha + ((bg_hex >> 8) & 0xFF) * (1 - alpha);
	b = (fg_hex & 0xFF) * alpha + (bg_hex & 0xFF) * (1 - alpha);
	return ((r << 16) | (g << 8) | b);
}

void	print_border(t_fractal *fractal)
{
	int	i;
	int	j;
	int	crd;

	i = 80;
	while (i < 300)
	{
		j = 30;
		while (j < 180)
		{
			crd = (j * fractal->line_length >> 2) + i;
			if (j == 30 || j == 60 || j == 90 || j == 120 || j == 150
				|| j == 179 || i == 80 || i == 299)
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
		while (j < 180)
		{
			crd = (j * fractal->line_length >> 2) + i;
			fractal->addr[crd] = blend_colors(0x5f5f5f, fractal->addr[crd],
					0.6);
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
	mlx_string_put(fractal->mlx, fractal->mlx_win, 190, pos, 0x000000, tmp);
	free(tmp);
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
	else if (fractal->name == 't')
		mlx_string_put(fractal->mlx, fractal->mlx_win, 190, 50, 0x000000,
			"tricorn");
	print_double_info(fractal, "Max iter:", fractal->max_iter, 80);
	print_double_info(fractal, "Zoom:", fractal->zoom, 110);
	print_double_info(fractal, "x offset:", fractal->offset_x, 140);
	print_double_info(fractal, "y offset:", fractal->offset_y, 170);
}
