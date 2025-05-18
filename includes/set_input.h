/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_input.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 14:48:47 by vblanc            #+#    #+#             */
/*   Updated: 2025/05/18 14:56:30 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_INPUT_H
# define SET_INPUT_H

# include "exec.h"

char	*set_readline_prompt(t_context *ctx);
int		is_valid_rl_input(char *input, t_context **ctx);
char	**get_input(t_context *ctx);
void	set_input(t_context **ctx);

#endif