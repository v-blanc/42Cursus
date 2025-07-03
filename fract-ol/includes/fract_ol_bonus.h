/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:56:26 by vblanc            #+#    #+#             */
/*   Updated: 2025/04/23 20:38:47 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_BONUS_H
# define FRACT_OL_BONUS_H

/* Libraries */

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
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
# define Q_MAC 24
# define Q_LINUX 113
# define W_MAC 25
# define W_LINUX 119
# define R_MAC 15
# define R_LINUX 114
# define C_MAC 8
# define C_LINUX 99

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

typedef struct s_thread_data
{
	t_fractal	*fractal;
	int			start_line;
	int			end_line;
}				t_thread_data;

/* draw.c */

void			my_mlx_pixel_put(t_fractal *fractal, int x, int y, int color);
void			init_fractal_values(t_fractal *fractal, int x, int y);
void			sub_draw_fractal(t_fractal *fractal, int x, int y);
void			draw_fractal(t_fractal *fractal);

/* draw_multithreads.c */

void			draw_fractal_threads(t_fractal *fractal);

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

/* put_image.c */

void			put_image(t_fractal *fractal);

/* utils.c */

double			ft_atof(const char *str);
char			*ft_dtoa_2f(double f);
int				blend_colors(int fg_hex, int bg_hex, double alpha);

#endif
