/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 10:41:01 by yabokhar          #+#    #+#             */
/*   Updated: 2025/05/15 12:47:03 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/* --------------------- Libraries --------------------- */

# include "../libft/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdarg.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <termios.h>
# include <unistd.h>

/* --------------------- Variables --------------------- */

# define PATH_MAX 4096
# define QUOTES_MAX 1024
# define FD_MAX 1024
# define BUFFER_SIZE 42
# define IN_FD 0
# define OUT_FD 1

# define RED "\001\033[1;31m\002"
# define GREEN "\001\033[1;32m\002"
# define BLUE "\001\033[1;34m\002"
# define RESET "\001\033[0m\002"

/* --------------------- Garbage Collector --------------------- */

typedef struct s_gc
{
	int						perm;
	void					*mem;
	struct s_gc				*next;
}							t_gc;

void						*gc_malloc(size_t size, t_gc **head);
void						**gc_malloc_array(size_t size, t_gc **head);
void						*gc_malloc_perm(size_t size, t_gc **head);
void						**gc_malloc_array_perm(size_t size, t_gc **head);
void						gc_free(void *mem, t_gc **head);
void						gc_free_array(char **array, t_gc **head);
void						gc_free_all(t_gc **head);
void						gc_free_all_perm(t_gc *head);
char						*gc_strjoin(char *s1, char *s2, t_gc **head);
char						*gc_strjoin_perm(char *s1, char *s2, t_gc **head);
char						*gc_strdup(const char *s, t_gc **head);
char						*gc_strdup_perm(const char *s, t_gc **head);
char						*gc_substr(char const *s, unsigned int start,
								size_t len, t_gc **head);
char						**gc_split(char const *s, char c, t_gc **head);
char						*gc_itoa(int n, t_gc **head);
char						*gc_strndup(const char *s, size_t n, t_gc **head);
int							gc_setenv(char *name, char *value, t_gc **head);

/* --------------------- Context --------------------- */

typedef struct s_context
{
	int						argc;
	char					**argv;
	int						last_exit_status;
	int						last_node_type;
	struct termios			orig_term;
	int						backup_fds[2];
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

int							is_operator_char(char c);
t_token_type				get_op_type(const char *s, int *len);
t_token						*new_token(t_token_type type, char quote_type,
								const char *value, t_gc **head);
void						token_add_back(t_token **tokens, t_token *new);

int							tokenizer(t_token **tokens, const char *s,
								t_context **ctx);

int							expand_tilde(char **word, t_gc **head);
int							expand_one_token(char **w, int len_w,
								t_context *ctx);
int							expander(t_token **tokens, t_context *ctx);
int							merge_tokens(t_token **tokens, t_gc **head);

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
		} s_red;
	} u_data;
}							t_ast;

int							is_redirection(t_token_type type);
int							count_cmd_args(t_token *tok);
int							count_cmd_redir(t_token *tok, t_context **ctx);
int							get_fd_source(t_token_type type);

t_ast						*parse_primary(t_token **tokens, t_context **ctx);
t_ast						*parse_pipeline(t_token **tokens, t_context **ctx);
t_ast						*parse_command(t_token **tok, t_context **ctx);
t_ast						*parser(t_token **tokens, t_context **ctx);

int							parsing(char *input, t_ast **ast,
								t_context **context);

void						print_ast(t_ast *node, int depth);

/* --------------------- Execution --------------------- */

int							builtins_manager(t_ast *ast, t_context **context);
int							is_builtin(char *command);
void						exec_manager(t_ast *ast, t_context **context);

int							execute_ast(t_ast *node, t_context *ctx);
int							execute_command(t_ast *node, t_context *ctx);
int							handle_pipes(t_ast *pipe_node, t_context *ctx);
int							handle_heredoc(const char *dlim, const bool hdoc);
// bool						is_builtin(char *query);
// int						execute_builtin(t_ast *command, t_context *ctx);
void						close_pipes(int (*pipes)[2], int cmds_nb);
void						refresh(int backup_fds[2]);

/* --------------------- Buildins --------------------- */

int							cd(int fd, int args_count, char **args,
								t_gc **head);
int							echo(int fd, char **arguments);
int							env(t_ast *ast, t_context **context);
int							exit_(int ac, char **av, t_context **context);
int							is_valid_export(char *str);
int							export(int fd, int args_count, char **args,
								t_gc **head);
int							pwd(int fd);
int							unset(char **to_unset, t_gc **head);

/* --------------------- Signals --------------------- */

void						init_sig(void);

/* --------------------- Utils --------------------- */

char						*set_readline_prompt(t_context *ctx);
int							is_valid_rl_input(char *input, t_context **ctx);
char						**get_input(void);
bool						input_came_from_heredoc(t_ast *c);

char						*get_next_line(int fd);
size_t						string_length(const char *s);
char						*duplicate_(char *buffer);
char						*concatenate_(char *line, char *buffer);
void						shift_(char *buffer);
bool						string_contains_newline(char *buffer);

int							print(int fd, const char *format, ...);

int							exit_eof(t_context **context);

#endif
