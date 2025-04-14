#include "../../include/minishell.h"

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

int	echo(char **arguments)
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
		write(1, arguments[i], ft_strlen(arguments[i]));
		if (arguments[i + 1])
			write(1, " ", 1);
		i++;
	}
	if (new_line_to_print)
		write(1, "\n", 1);
	return (EXIT_SUCCESS);
}
