#ifndef MINISHELL_H
# define MINISHELL_H

/* Libraries */

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

/* Variables */

# define PATH_MAX 4096
# define QUOTES_MAX 1024

/* Structures */

typedef struct s_gc
{
	void		*mem;
	struct s_gc	*next;
}				t_gc;

typedef struct s_stack
{
	char		data[QUOTES_MAX];
	int			top;
}				t_stack;

/* stack.c */

void			init_stack(t_stack *stack);
int				is_stack_empty(t_stack *stack);
int				push_stack(t_stack *stack, char c);
char			pop_stack(t_stack *stack);
char			top_stack(t_stack *stack);

/* buildins */

int				cd(char *path, t_gc **head);
int				echo(char *to_print, bool n_option_flag);
int				env(void);
int				ft_exit(int status);
int				export(char *name, char *value, t_gc **head);
int				pwd(void);
int				unset(char **to_unset, t_gc **head);

/* sig.c */

void			init_sig(void);

/* garbage_collector.c */

void			*gc_malloc(size_t size, t_gc **head);
void			**gc_malloc_array(size_t size, t_gc **head);
void			gc_free(void *mem, t_gc **head);
void			gc_free_array(char **array, t_gc **head);
void			gc_free_all(t_gc *head);
char			*gc_strjoin(char *s1, char *s2, t_gc **head);
char			*gc_strdup(const char *s, t_gc **head);
char			*gc_substr(char const *s, unsigned int start, size_t len,
					t_gc **head);
char			**gc_split(char const *s, char c, t_gc **head);

/* utils_env.c */

int				gc_setenv(char *name, char *value, t_gc **head);

/* parse.c */

int				get_env_value(char **input_with_env, char *input_str,
					t_gc **head);
int				test_quotes_validity(char *input_str);
int				parse_quotes(char *input, char **new_input, t_gc **head);
int				testing_input(char *input, t_gc **head);

#endif
