
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

# define PATH_MAX 4096 - 1

/* Structures */

//....

/* buildins */

int		cd(char *path);
int		echo(char *to_print, bool n_option_flag);
int		env(void);
int		ft_exit(int status);
int		export(char *name);
int		pwd(void);

/* signals */

void	init_sig(void);

/* utils_env.c */

int		ft_setenv(char *name, char *value);

#endif
