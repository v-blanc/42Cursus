#include "../../include/minishell.h"

int	echo(char *to_print, bool n_option_flag)
{
	printf("%s", to_print);
	if (n_option_flag == 0)
		printf("\n");
	return (0);
}
