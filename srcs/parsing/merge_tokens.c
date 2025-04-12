#include "../../include/minishell.h"

static int	sub_merge_tokens(t_token *curr, t_token *next, t_gc **head)
{
	char	*joined;
	int		len_curr_value;
	int		len_joined;

	len_curr_value = ft_strlen(curr->value);
	len_joined = len_curr_value + ft_strlen(next->value);
	joined = gc_malloc(len_joined + 1, head);
	if (!joined)
		return (1);
	ft_strlcpy(joined, curr->value, len_curr_value + 1);
	ft_strlcat(joined, next->value, len_joined + 1);
	gc_free(curr->value, head);
	curr->value = joined;
	curr->next = next->next;
	gc_free(next, head);
	return (0);
}

int	merge_tokens(t_token **tokens, t_gc **head)
{
	t_token	*curr;
	t_token	*next;

	curr = *tokens;
	while (curr && curr->next)
	{
		next = curr->next;
		if (curr->type == WORD && next->type == WORD && curr->joined_next)
		{
			if (sub_merge_tokens(curr, next, head))
				return (1);
		}
		else
			curr = curr->next;
	}
	return (0);
}
