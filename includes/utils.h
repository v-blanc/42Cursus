/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 12:49:42 by vblanc            #+#    #+#             */
/*   Updated: 2025/05/21 16:48:14 by vblanc           ###   ########.fr       */
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

// print

void	print(int fd, const char *format, ...);

// exit

int		exit_eof(t_context **context);

// fds

void	close_heredoc_fds(t_ast *node);
void	refresh(int backup_fds[2]);
void	command_fd_dup(int cmd_backup_fds[2]);
void	command_refresh(int cmd_backup_fds[2]);

#endif
