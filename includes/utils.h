/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 12:49:42 by vblanc            #+#    #+#             */
/*   Updated: 2025/05/18 14:56:40 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "gc_functions.h"
# include "variables.h"
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>

// main_utils

int		init_environ(t_gc **head);
int		init_context(t_context **context, int argc, char **argv, t_gc **head);
int		update_shlvl(t_gc **head);

// sig

void	init_sig(void);

// get_next_line

size_t	string_length(const char *s);
char	*duplicate_(char *buffer, t_context *ctx);
char	*concatenate_(char *line, char *buffer, t_context *ctx);
void	shift_(char *buffer);
bool	string_contains_newline(char *buffer);
char	*get_next_line(int fd, t_context *ctx);

// print

void	print(int fd, const char *format, ...);

// pointer

void	set_ptr(void *ptr);
void	*get_ptr(void);

// exit

int		exit_eof(t_context **context);

#endif