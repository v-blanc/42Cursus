/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 17:20:01 by vblanc            #+#    #+#             */
/*   Updated: 2025/02/06 09:18:48 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

// TODO: change Usage

static void	print_usage(void)
{
	write(1, "Usage: ./fract-ol [mandelbrot/julia/lotus]\n", 38);
}

static void	check_args(int argc, char **argv)
{
	if (argc < 2)
	{
		print_usage();
		exit(1);
	}
	if (!ft_strncmp(argv[1], "mandelbrot", ft_strlen(argv[1])))
		return ;
	else if (!ft_strncmp(argv[1], "julia", ft_strlen(argv[1])) && (argc == 2
			|| argc == 4))
		return ;
	else if (!ft_strncmp(argv[1], "lotus", ft_strlen(argv[1])))
		return ;
	else if ((ft_strncmp(argv[1], "-h", ft_strlen(argv[1]))
			&& ft_strncmp(argv[1], "--help", ft_strlen(argv[1]))) || argc != 2)
		write(1, "Fractal name not valid\n", 23);
	print_usage();
	exit(1);
}

static void	init_all(t_fractal *fractal, char **argv)
{
	init_mlx(fractal);
	init_fractal_name(fractal, &argv[1]);
	init_fractal_window(fractal);
}

static void	set_mlx_hooks(t_fractal *fractal)
{
	mlx_key_hook(fractal->mlx_win, hooks_manager, fractal);
	mlx_mouse_hook(fractal->mlx_win, zoom_manager, fractal);
	mlx_hook(fractal->mlx_win, 17, 0, exit_manager, fractal);
}

int	main(int argc, char **argv)
{
	t_fractal	*fractal;

	check_args(argc, argv);
	fractal = malloc(sizeof(t_fractal));
	init_all(fractal, argv);
	set_mlx_hooks(fractal);
	draw_fractal(fractal);
	mlx_loop(fractal->mlx);
	return (0);
}
