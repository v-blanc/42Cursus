/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 19:20:28 by vblanc            #+#    #+#             */
/*   Updated: 2025/02/04 19:41:19 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPLEX_H
# define COMPLEX_H

/* Structure */

typedef struct s_complex
{
	float	real;
	float	img;
}			t_complex;

/* Functions */

void		ft_set_complex(t_complex *c, float real, float img);
t_complex	ft_add_complex(t_complex c1, t_complex c2);
t_complex	ft_mul_complex(t_complex c1, t_complex c2);
float		ft_mod_complex(t_complex c);

#endif