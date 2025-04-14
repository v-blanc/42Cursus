#include "../../include/minishell.h"

static int	is_valid_arg(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (!isdigit(arg[i]))
			return (0);
		i++;
	}
	// TODO: handle number too big
	return (1);
}

int	exit_(int args_count, char **args, t_context **context)
{
	int	exit_status;

	exit_status = 0;
	printf("exit\n");
	if (args_count == 2)
	{
		if (!is_valid_arg(args[0]))
		{
			printf("exit: %s: numeric argument required", args[0]);
			(*context)->last_exit_status = 2;
		}
		exit_status = ft_atoi(args[0]);
		exit_status %= 255; // TODO: check if it works well
	}
	else if (args_count > 2)
	{
		printf("exit: too many arguments\n");
		(*context)->last_exit_status = 1;
		return (0);
	}
	gc_free_all_perm(*((*context)->head));
	rl_clear_history();
	exit(exit_status);
	return (0);
}
