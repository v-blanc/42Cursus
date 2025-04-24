#include "minishell.h"


int	count_cmd_args(t_token *tok)
{
	int	count;

	count = 0;
	while (tok)
	{
		if (is_redirection(tok->type))
		{
			tok = tok->next;
			if (tok)
				tok = tok->next;
		}
		else if (tok->type == WORD)
		{
			count++;
			tok = tok->next;
		}
		else
			tok = tok->next;
	}
	return (count);
}

int	count_cmd_redir(t_token *tok, t_context **ctx)
{
	int	count;

	count = 0;
	while (tok)
	{
		if (is_redirection(tok->type))
		{
			if (!tok->next || tok->next->type != WORD)
			{
				print(2, "syntax error\n");
				(*ctx)->last_exit_status = 2;
				return (-1);
			}
			count++;
			tok = tok->next->next;
		}
		else
			tok = tok->next;
	}
	return (count);
}
