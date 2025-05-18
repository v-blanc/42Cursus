/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 13:50:02 by vblanc            #+#    #+#             */
/*   Updated: 2025/05/18 14:56:16 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include "builtins.h"
# include <signal.h>
# include <sys/stat.h>
# include <sys/wait.h>

int		builtins_manager(t_ast *ast, t_context **context);
bool	is_builtin(char *command);

int		execute_ast(t_ast *node, t_context *ctx);
int		execute_command(t_ast *node, t_context *ctx);
char	*track_paths(char *command, t_gc **head);
int		handle_pipes(t_ast *pipe_node, t_context *ctx);
int		handle_redirections(t_ast *c, t_context *ctx);
int		handle_heredoc(char *dlim, const bool hdoc, t_context *ctx);
void	refresh(int backup_fds[2]);

#endif