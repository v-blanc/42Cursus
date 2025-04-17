#include "minishell.h"

char	*set_readline_prompt(t_context *context, t_gc **head)
{
	char	*pwd;
	char	*home_path;
	char	*rl_prompt;

	(void)context;
	pwd = getenv("PWD");
	if (!pwd)
		return (NULL);
	home_path = getenv("HOME");
	if (!home_path)
		return (NULL);
	if (home_path != NULL && !ft_strncmp(pwd, home_path, ft_strlen(home_path)))
	{
		ft_strlcpy(pwd, pwd + ft_strlen(home_path) - 1, PATH_MAX);
		pwd[0] = '~';
	}
	rl_prompt = gc_strjoin(GREEN "minishell" RESET ":" BLUE, pwd, head);
	if (!rl_prompt)
		return (NULL);
	rl_prompt = gc_strjoin(rl_prompt, RESET "$ ", head);
	if (!rl_prompt)
		return (NULL);
	if (context->last_exit_status == 0)
		rl_prompt = gc_strjoin(GREEN "➜  " RESET, rl_prompt, head);
	else
		rl_prompt = gc_strjoin(RED "➜  " RESET, rl_prompt, head);
	if (!rl_prompt)
		return (NULL);
	return (rl_prompt);
}
