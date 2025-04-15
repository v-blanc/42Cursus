#include "minishell.h"

static bool	is_flag_n(char *argument)
{
	size_t	i;

	if (!argument || !argument[0])
		return (false);
	i = -1;
	while (argument[++i])
	{
		if (argument[0] != '-')
			return (false);
		if (i != 0 && argument[i] != 'n')
			return (false);
	}
	return (true);
}

int	echo(int fd, char **arguments)
{
	bool	new_line_to_print;
	size_t	i;

	if (!arguments)
		return (EXIT_FAILURE);
	new_line_to_print = true;
	i = 0;
	while (is_flag_n(arguments[i]))
	{
		new_line_to_print = false;
		i++;
	}
	while (arguments[i])
	{
		print(fd, "%s", arguments[i]);
		if (arguments[i + 1])
			print(fd, " ");
		i++;
	}
	if (new_line_to_print)
		print(fd, "\n");
	return (EXIT_SUCCESS);
}
