/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 13:44:25 by vblanc            #+#    #+#             */
/*   Updated: 2025/05/18 14:28:07 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "parsing.h"
# include <fcntl.h>
# include <readline/readline.h>
# include <sys/stat.h>

// Mandatory

int		cd(int fd, int args_count, char **args, t_gc **head);
int		echo(int fd, char **arguments);
int		env(t_ast *ast, t_context **context);
int		exit_(int ac, char **av, t_context **context);
int		is_valid_export(char *str);
int		export(int fd, int args_count, char **args, t_gc **head);
int		pwd(int fd);
int		unset(char **to_unset, t_gc **head);

// Bonus

int		repeat(t_ast *ast, t_context **ctx);
int		alias(int argc, char **argv, t_context *ctx);
void	create_aliases(t_context *ctx);
void	add_alias(const char *k, const char *v, t_context *x);

#endif