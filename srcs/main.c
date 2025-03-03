/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 17:20:01 by vblanc            #+#    #+#             */
/*   Updated: 2025/03/03 17:56:15 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

static void	print_usage(void)
{
	write(1, "Usage: ./fract-ol [-h/mandelbrot/julia [cx cy]]\n", 49);
	write(1, "________________________________________________________\n", 58);
	write(1, "\nKeyborad controls:\n", 20);
	write(1, "\tESC: exit\n\tMouse: zoom\n", 25);
	write(1, "________________________________________________________\n", 58);
	write(1, "\nSome julia examples:\n", 23);
	write(1, "\t./fractol julia -0.75 0\n\t./fractol julia -0.39 -0.59\n", 55);
	write(1, "\t./fractol julia 0.285 0.01\n\t./fractol julia 0 -1\n", 51);
	write(1, "\t./fractol julia -0.12 0.75\n", 29);
}

static int	check_julia_args(int argc, char **argv)
{
	int	i;
	int	point_flag;
	int	j;

	i = 2;
	while (i < argc)
	{
		point_flag = 0;
		j = 0;
		if (argv[i][j] == '-')
			j++;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
			{
				if (argv[i][j] == '.' && point_flag < 1)
					point_flag++;
				else
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

static void	check_args(int argc, char **argv)
{
	if (argc < 2)
	{
		print_usage();
		exit(1);
	}
	if (!ft_strncmp(argv[1], "mandelbrot", ft_strlen(argv[1]) + 1) && argc == 2)
		return ;
	else if (!ft_strncmp(argv[1], "julia", ft_strlen(argv[1]) + 1)
		&& check_julia_args(argc, argv) == 0 && (argc == 2 || argc == 4))
		return ;
	else if ((ft_strncmp(argv[1], "-h", ft_strlen(argv[1]) + 1)
			&& ft_strncmp(argv[1], "--help", ft_strlen(argv[1])) + 1)
		|| argc != 2)
		print_usage();
	exit(1);
}

static void	init_all(t_fractal *fractal, char **argv)
{
	init_mlx(fractal);
	init_fractal_name(fractal, &argv[1]);
	init_fractal_window(fractal);
	init_fractal_colors(fractal);
}

int	main(int argc, char **argv)
{
	char		**argv_cpy;
	t_fractal	*fractal;

	argv_cpy = argv;
	check_args(argc, argv_cpy);
	fractal = ft_calloc(sizeof(t_fractal), 1);
	if (!fractal)
		return (1);
	init_all(fractal, argv);
	mlx_key_hook(fractal->mlx_win, hooks_manager, fractal);
	mlx_mouse_hook(fractal->mlx_win, zoom_manager, fractal);
	mlx_hook(fractal->mlx_win, 17, 0, exit_manager, fractal);
	draw_fractal(fractal);
	mlx_loop(fractal->mlx);
	return (0);
}
