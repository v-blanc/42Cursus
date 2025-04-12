#include "../../include/minishell.h"

static int	expand_tilde(char **word, t_gc **head)
{
	char	*home;
	char	*result;
	int		len_home;
	int		len_result;

	if ((*word)[0] != '~')
		return (0);
	if ((*word)[1] && (*word)[1] != '/' && !isspace((*word)[1]))
		return (0);
	home = getenv("HOME");
	if (!home)
		return (0);
	len_home = ft_strlen(home);
	len_result = len_home + ft_strlen(&(*word)[1]);
	result = gc_malloc(len_result + 1, head);
	if (!result)
		return (1);
	ft_strlcpy(result, home, len_home + 1);
	ft_strlcat(result, &(*word)[1], len_result + 1);
	gc_free(word, head);
	(*word) = result;
	return (0);
}

int	expander(t_token **tokens, t_context *context, t_gc **head)
{
	t_token	*cur;

	cur = *tokens;
	while (cur)
	{
		if (cur->type == WORD && cur->quote != SINGLE_QUOTE && cur->value)
		{
			if (expand_tilde(&cur->value, head))
				return (1);
			if (expand_one_token(&cur->value, context, head))
				return (1);
		}
		cur = cur->next;
	}
	return (0);
}
