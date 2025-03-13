#include "../../include/minishell.h"


int	echo(char *to_print, bool n_option_flag)
{
	printf("%s", to_print);
	if (n_option_flag == 0)
		write(1, "\n", 1);
	return (0);
}
