/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 17:20:01 by vblanc            #+#    #+#             */
/*   Updated: 2025/02/04 19:43:47 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}			t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

void	ft_printf_fractal(t_data img)
{
	int			x;
	int			y;
	t_complex	z;
	int			max_iter;
	int			i;
	float		tmp;
	int			zoom;
	float		x1;
	float		x2;
	float		y1;
	float		y2;
	float		offset_x;
	float		offset_y;

	x1 = -2.1;
	x2 = 0.6;
	y1 = -1.2;
	y2 = 1.2;
	zoom = 100;
	offset_x = (x2 - x1) / zoom;
	offset_y = (y2 - y1) / zoom;
	max_iter = 100;
	x = 0;
	while (x < offset_x)
	{
		y = 0;
		while (y < offset_y)
		{
			ft_set_complex(&z, 0, 0);
			i = 0;
			while (i < max_iter && ft_mod_complex(z) < 4)
			{
				tmp = z.real;
				z.real = z.real * z.real - z.img * z.img + (x / zoom) + x1;
				z.img = 2 * tmp * z.img + (y / zoom) + y1;
				i++;
			}
			my_mlx_pixel_put(&img, x, y, 0x00FF00);
			printf("x: %d, y: %d, i: %d\n", x, y, i);
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
