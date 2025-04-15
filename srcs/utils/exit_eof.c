#include "minishell.h"

int	exit_eof(t_context **context)
{
	int	exit_status;

	print(1, "exit\n");
	exit_status = (*context)->last_exit_status % 256;
	gc_free_all_perm(*((*context)->head));
	rl_clear_history();
	exit(exit_status);
	return (0);
}
