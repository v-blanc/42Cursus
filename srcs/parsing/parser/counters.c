#include "minishell.h"

static int	is_redirection(t_token_type type)
{
	return (type == REDIR_IN || type == REDIR_OUT || type == REDIR_APPEND
		|| type == REDIR_HEREDOC);
}

int	count_cmd_args(t_token *tok)
{
	int	count;

	count = 0;
	while (tok && tok->type == WORD)
	{
		count++;
		tok = tok->next;
	}
	return (count);
}

int	count_cmd_redir(t_token *tok, t_context **ctx)
{
	int	count;

	count = 0;
	while (tok && tok->type == WORD)
		tok = tok->next;
	while (tok && is_redirection(tok->type))
	{
		if (!tok->next || tok->next->type != WORD)
		{
			// if (tok->type != REDIR_HEREDOC)
			// {
			print(2, "syntax error\n");
			(*ctx)->last_exit_status = 2;
			return (-1);
			// }
		}
		count++;
		tok = tok->next->next;
	}
	return (count);
}
