/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:56:26 by vblanc            #+#    #+#             */
/*   Updated: 2025/03/13 10:22:08 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

/* Libraries */

# include "../includes/libft/libft.h"
# include "../includes/minilibx-linux/mlx.h"
# include <pthread.h>

/* Macros */

# define WINDOW_HEIGHT 1920
# define WINDOW_WIDTH 1080
// # define WINDOW_HEIGHT 720
// # define WINDOW_WIDTH 480
# define THREADS 8
# define COLOR_NUMBER 5

# define ESC_MAC 53
# define ESC_LINUX 65307
# define UP_MOUSE 4
# define DOWN_MOUSE 5

/* Structures */

typedef struct s_fractal
{
	void		*mlx;
	void		*mlx_win;
	void		*img;
	int			*addr;
	int			bpp;
	int			line_length;
	int			endian;
	char		name;
	double		zx;
	double		zy;
	double		cx;
	double		cy;
	double		zoom;
	double		inv_zoom;
	double		offset_x;
	double		offset_y;
	int			max_iter;
	int			*colors;
	int			color_index;
	int			mthreads_flag;
}				t_fractal;

/* draw.c */

void			my_mlx_pixel_put(t_fractal *fractal, int x, int y, int color);
void			init_fractal_values(t_fractal *fractal, int x, int y);
void			sub_draw_fractal(t_fractal *fractal, int x, int y);
void			draw_fractal(t_fractal *fractal);

/* hooks.c */

int				zoom_manager(int keycode, int x_mouse, int y_mouse,
					t_fractal *fractal);
int				exit_manager(t_fractal *fractal);
int				hooks_manager(int keycode, t_fractal *fractal);

/* init.c */

void			init_mlx(t_fractal *fractal);
void			init_fractal_name(t_fractal *fractal, char **input);
void			init_fractal_window(t_fractal *fractal);
void			init_fractal_colors(t_fractal *fractal);

/* utils.c */

double			ft_atof(const char *str);
char			*ft_dtoa_2f(double f);

#endif
