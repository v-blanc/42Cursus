#ifndef MINISHELL_H
# define MINISHELL_H

/* Libraries */

# include "../libft/libft.h"
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

/* Variables */

# define PATH_MAX 4096

/* Structures */

typedef struct s_garbage_collector
{
	void						*mem;
	struct s_garbage_collector	*next;
}								t_garbage_collector;

/* buildins */

int								cd(char *path, t_garbage_collector **head);
int								echo(char *to_print, bool n_option_flag);
int								env(void);
int								ft_exit(int status);
int								export(char *name, char *value,
									t_garbage_collector **head);
int								pwd(void);
int								unset(char **to_unset,
									t_garbage_collector **head);

/* sig.c */

void							init_sig(void);

/* garbage_collector.c */

void							*gc_malloc(size_t size,
									t_garbage_collector **head);
void							**gc_malloc_array(size_t size,
									t_garbage_collector **head);
void							gc_free(void *mem, t_garbage_collector **head);
void							gc_free_array(char **array,
									t_garbage_collector **head);
void							gc_free_all(t_garbage_collector *head);
char							*gc_strjoin(char *s1, char *s2,
									t_garbage_collector **head);

/* utils_env.c */

int								gc_setenv(char *name, char *value,
									t_garbage_collector **head);

#endif
