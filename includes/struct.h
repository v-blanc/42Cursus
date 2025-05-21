/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 13:24:41 by vblanc            #+#    #+#             */
/*   Updated: 2025/05/21 13:32:54 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "termios.h"
# include <stdbool.h>

/* --------------------------- Garbage Collector --------------------------- */

typedef struct s_gc
{
	int						perm;
	void					*mem;
	struct s_gc				*next;
}							t_gc;

/* --------------------------- Alias --------------------------- */

typedef struct s_alias
{
	char					*key;
	char					*value;
	struct s_alias			*next;
}							t_alias;

/* --------------------------- Context --------------------------- */

typedef struct s_context
{
	int						argc;
	char					**argv;
	int						last_exit_status;
	int						last_node_type;
	struct termios			orig_term;
	int						backup_fds[2];
	int						cmd_backup_fds[2];
	bool					in_subshell;
	t_gc					**head;
}							t_context;

/* --------------------------- Token types --------------------------- */

typedef enum e_token_type
{
	WORD,
	PIPE,
	REDIR_IN,
	REDIR_OUT,
	REDIR_APPEND,
	REDIR_HEREDOC,
	PAREN_OPEN,
	PAREN_CLOSE,
	AND,
	OR,
	END
}							t_token_type;

typedef enum e_quote_type
{
	NO_QUOTE,
	SINGLE_QUOTE,
	DOUBLE_QUOTE
}							t_quote_type;

typedef struct s_token
{
	t_token_type			type;
	t_quote_type			quote;
	char					*value;
	int						joined_next;
	struct s_token			*next;
}							t_token;

/* --------------------------- AST --------------------------- */

typedef enum e_node_type
{
	NODE_CMD,
	NODE_REDIR,
	NODE_PIPE,
	NODE_BINARY_OP,
	NODE_PAREN,
}							t_node_type;

typedef struct s_ast
{
	t_node_type				type;
	union
	{
		struct
		{
			int				args_count;
			char			**args;
			int				redir_count;
			struct s_ast	**redirs;
		} s_cmd;
		struct
		{
			int				cmd_count;
			struct s_ast	**commands;
		} s_pipe;
		struct
		{
			int				op;
			struct s_ast	*left;
			struct s_ast	*right;
		} s_op;
		struct
		{
			struct s_ast	*content;
			int				redir_count;
			struct s_ast	**redirs;
		} s_par;
		struct
		{
			int				op;
			int				fd_source;
			char			*target;
			bool			to_expand;
			int				heredoc_fd;
		} s_red;
	} u_data;
}							t_ast;

#endif
