/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_multithreads_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 22:37:49 by vblanc            #+#    #+#             */
/*   Updated: 2025/03/03 14:33:40 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol_bonus.h"

static void	*draw_fractal_thread(void *arg)
{
	t_thread_data	*data;
	t_fractal		local_fractal;
	int				x;
	int				y;

	data = (t_thread_data *)arg;
	x = data->start_line;
	while (x < data->end_line)
	{
		y = 0;
		while (y < WINDOW_WIDTH)
		{
			local_fractal = *(data->fractal);
			sub_draw_fractal(&local_fractal, x, y);
			y++;
		}
		x++;
	}
	return (NULL);
}

void	draw_fractal_threads(t_fractal *fractal)
{
	pthread_t		threads[THREADS];
	t_thread_data	thread_data[THREADS];
	int				lines_per_thread;
	int				i;

	lines_per_thread = WINDOW_HEIGHT / THREADS;
	i = 0;
	while (i < THREADS)
	{
		threads[i] = 0;
		thread_data[i].fractal = fractal;
		thread_data[i].start_line = i * lines_per_thread;
		if (i == THREADS - 1)
			thread_data[i].end_line = WINDOW_HEIGHT;
		else
			thread_data[i].end_line = (i + 1) * lines_per_thread;
		pthread_create(&threads[i], NULL, draw_fractal_thread, &thread_data[i]);
		i++;
	}
	i = 0;
	while (i < THREADS)
		pthread_join(threads[i++], NULL);
	put_image(fractal);
}
