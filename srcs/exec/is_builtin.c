#include "../../include/minishell.h"

int	is_builtin(char *command)
{
	if (!ft_strncmp(command, "cd", 3))
		return (1);
	if (!ft_strncmp(command, "echo", 5))
		return (1);
	if (!ft_strncmp(command, "env", 4))
		return (1);
	if (!ft_strncmp(command, "exit", 5))
		return (1);
	if (!ft_strncmp(command, "export", 8))
		return (1);
	if (!ft_strncmp(command, "pwd", 4))
		return (1);
	if (!ft_strncmp(command, "unset", 6))
		return (1);
	return (0);
}
