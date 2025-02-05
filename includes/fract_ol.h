/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:56:26 by vblanc            #+#    #+#             */
/*   Updated: 2025/02/05 08:28:11 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

/* Libraries */

# include "../includes/libft/libft.h"
# include "../includes/minilibx-linux/mlx.h"
# include <time.h>   // TODO: remove
# include <unistd.h>

/* Macros */

# define WINDOW_HEIGHT 720
# define WINDOW_WIDTH 480

# define ESC_MAC 53
# define ESC_LINUX 65307
# define LEFT_MAC 123
# define LEFT_LINUX 65361
# define RIGHT_MAC 124
# define RIGHT_LINUX 65363
# define DOWN_MAC 125
# define DOWN_LINUX 65364
# define UP_MAC 126
# define UP_LINUX 65362
# define UP_MOUSE 4
# define DOWN_MOUSE 5
# define P_MAC 35
# define P_LINUX 112
# define M_MAC 46
# define M_LINUX 109

/* Structures */

typedef struct s_fractal
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	void	*addr;
	int		bpp;
	int		line_length;
	int		endian;
	char	name;
	double	zx;
	double	zy;
	double	cx;
	double	cy;
	double	zoom;
	double	offset_x;
	double	offset_y;
	int		max_iter;
}			t_fractal;

/* draw.c */

void		draw_fractal(t_fractal *fractal);

/* hooks.c */

int			zoom_manager(int keycode, int x_mouse, int y_mouse,
				t_fractal *fractal);
int			exit_manager(t_fractal *fractal);
int			hooks_manager(int keycode, t_fractal *fractal);

/* init.c */

void		init_mlx(t_fractal *fractal);
void		init_fractal_name(t_fractal *fractal, char **input);
void		init_fractal_window(t_fractal *fractal);

#endif
