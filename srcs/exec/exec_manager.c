#include "../../include/minishell.h"

void	builtins_manager(t_ast *ast, t_context **context)
{
	int		args_count;
	char	**args;
	int		return_value;

	args_count = ast->u_data.s_cmd.args_count;
	args = ast->u_data.s_cmd.args;
	if (!ft_strncmp(args[0], "cd", 3))
		return_value = cd(args_count, args + 1, (*context)->head);
	if (!ft_strncmp(args[0], "echo", 5))
		return_value = echo(args + 1);
	if (!ft_strncmp(args[0], "env", 4))
		return_value = env(args_count);
	if (!ft_strncmp(args[0], "exit", 5))
		return_value = exit_(args_count, args + 1, context);
	if (!ft_strncmp(args[0], "export", 8))
		return_value = export(args_count, args + 1, (*context)->head);
	if (!ft_strncmp(args[0], "pwd", 4))
		return_value = pwd();
	if (!ft_strncmp(args[0], "unset", 6))
		return_value = unset(args + 1, (*context)->head);
	if (return_value)
	{
		printf(">>> BUILTINS ERROR\n");
	}
	return ;
}

void	exec_manager(t_ast *ast, t_context **context)
{
	if (ast->type == NODE_CMD)
	{
		if (is_builtin(ast->u_data.s_cmd.args[0]))
			builtins_manager(ast, context);
		else
			printf("Not builtins command: not working yet\n");
	}
}
