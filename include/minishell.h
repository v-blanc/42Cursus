#ifndef MINISHELL_H
# define MINISHELL_H

/* --------------------- Libraries --------------------- */

# include "../libft/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

/* --------------------- Variables --------------------- */

# define PATH_MAX 4096
# define QUOTES_MAX 1024

/* --------------------- Garbage Collector --------------------- */

typedef struct s_gc
{
	void					*mem;
	struct s_gc				*next;
}							t_gc;

void						*gc_malloc(size_t size, t_gc **head);
void						**gc_malloc_array(size_t size, t_gc **head);
void						gc_free(void *mem, t_gc **head);
void						gc_free_array(char **array, t_gc **head);
void						gc_free_all(t_gc *head);
char						*gc_strjoin(char *s1, char *s2, t_gc **head);
char						*gc_strdup(const char *s, t_gc **head);
char						*gc_substr(char const *s, unsigned int start,
								size_t len, t_gc **head);
char						**gc_split(char const *s, char c, t_gc **head);

/* --------------------- Context --------------------- */

typedef struct s_context
{
	int						argc;
	char					**argv;
	int						last_exit_status;
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
								t_gc **head);
int							expand_one_token(char **w, t_context *context,
								t_gc **head);
int							expander(t_token **tokens, t_context *context,
								t_gc **head);
int							merge_tokens(t_token **tokens, t_gc **head);

/* --------------------------- AST --------------------------- */

typedef enum e_node_type
{
	NODE_CMD,
	NODE_REDIR,
	NODE_PIPE,
	NODE_BINARY_OP
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
			int				op;
			int				fd_source;
			char			*target;
		} s_red;
	} u_data;
}							t_ast;

t_ast						*parse_command(t_token **tok, t_gc **head);
t_ast						*parser(t_token **tokens, t_gc **head);

void						print_ast(t_ast *node, int depth);

/* --------------------- Parsing --------------------- */

int							get_env_value(char **input_with_env,
								char *input_str, t_gc **head);
int							test_quotes_validity(char *input_str);
int							parse_quotes(char *input, char **new_input,
								t_gc **head);
// int							testing_input(char *input, t_gc **head);

/* --------------------- Stack --------------------- */

typedef struct s_stack
{
	char					data[QUOTES_MAX];
	int						top;
}							t_stack;

void						init_stack(t_stack *stack);
int							is_stack_empty(t_stack *stack);
int							push_stack(t_stack *stack, char c);
char						pop_stack(t_stack *stack);
char						top_stack(t_stack *stack);

/* --------------------- Buildins --------------------- */

int							cd(char *path, t_gc **head);
int							echo(char *to_print, bool n_option_flag);
int							env(void);
int							ft_exit(int status);
int							export(char *name, char *value, t_gc **head);
int							pwd(void);
int							unset(char **to_unset, t_gc **head);

/* --------------------- Signals --------------------- */

void						init_sig(void);

/* --------------------- Utils --------------------- */

int							gc_setenv(char *name, char *value, t_gc **head);

/* --------------------- Testing --------------------- */

int							testing_parser(char *input, t_context *context,
								t_gc **head);

#endif
