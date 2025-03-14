
#ifndef MINISHELL_H
# define MINISHELL_H

/* Libraries */

# include "../libft/libft.h"
# include <readline/history.h>
# include <readline/readline.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

/* Variables */

# define PATH_MAX 4096 - 1

/* Structures */

//....

/* echo.c */

int	echo(char *to_print, bool n_option_flag);

/* env.c */

int	env(void);

/* exit.c */

int	ft_exit(int status);

/* pwd.c */

int	pwd(void);

#endif
