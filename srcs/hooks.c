/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 02:56:36 by vblanc            #+#    #+#             */
/*   Updated: 2025/02/06 05:42:28 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

int	zoom_manager(int keycode, int x_mouse, int y_mouse, t_fractal *fractal)
{
	double	zoom_ratio;
	double	prev_zoom;

	zoom_ratio = 1.1;
	prev_zoom = fractal->zoom;
	if (keycode == UP_MOUSE)
	{
		fractal->zoom *= zoom_ratio;
	}
	else if (keycode == DOWN_MOUSE)
		fractal->zoom /= zoom_ratio;
	else
		return (0);
	fractal->offset_x = (x_mouse / prev_zoom + fractal->offset_x) - (x_mouse
			/ fractal->zoom);
	fractal->offset_y = (y_mouse / prev_zoom + fractal->offset_y) - (y_mouse
			/ fractal->zoom);
	fractal->inv_zoom = 1.0 / fractal->zoom;
	draw_fractal(fractal);
	return (0);
}

int	exit_manager(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx, fractal->img);
	mlx_destroy_window(fractal->mlx, fractal->mlx_win);
	mlx_destroy_display(fractal->mlx);
	free(fractal);
	exit(0);
	return (0);
}

int	hooks_manager(int keycode, t_fractal *fractal)
{
	if (keycode == ESC_MAC || keycode == ESC_LINUX)
		exit_manager(fractal);
	else if (keycode == P_MAC || keycode == P_LINUX)
		zoom_manager(UP_MOUSE, WINDOW_HEIGHT / 2, WINDOW_WIDTH / 2, fractal);
	else if (keycode == M_MAC || keycode == M_LINUX)
		zoom_manager(DOWN_MOUSE, WINDOW_HEIGHT / 2, WINDOW_WIDTH / 2, fractal);
	else
	{
		if (keycode == LEFT_MAC || keycode == LEFT_LINUX)
			fractal->offset_x -= 20 / fractal->zoom;
		else if (keycode == RIGHT_MAC || keycode == RIGHT_LINUX)
			fractal->offset_x += 20 / fractal->zoom;
		else if (keycode == DOWN_MAC || keycode == DOWN_LINUX)
			fractal->offset_y += 20 / fractal->zoom;
		else if (keycode == UP_MAC || keycode == UP_LINUX)
			fractal->offset_y -= 20 / fractal->zoom;
		else if (keycode == Q_MAC || keycode == Q_LINUX)
			fractal->max_iter += 10;
		else if (keycode == W_MAC || keycode == W_LINUX)
			fractal->max_iter -= 10;
		else if (keycode == R_MAC || keycode == R_LINUX)
			init_fractal_window(fractal);
		draw_fractal(fractal);
	}
	return (0);
}
