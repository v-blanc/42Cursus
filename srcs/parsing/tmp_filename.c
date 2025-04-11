#include "../../include/minishell.h"

int	merge_word_tokens(t_token **tokens, t_gc **head)
{
	t_token	*curr;
	t_token	*next;
	char	*joined;

	curr = *tokens;
	while (curr && curr->next)
	{
		next = curr->next;
		if (curr->type == WORD && next->type == WORD && curr->joined_next)
		{
			joined = gc_malloc(ft_strlen(curr->value) + ft_strlen(next->value)
					+ 1, head);
			if (!joined)
				return (1);
			ft_strlcpy(joined, curr->value, ft_strlen(curr->value) + 1);
			ft_strlcat(joined, next->value, ft_strlen(next->value) + 1);
			curr->value = joined;
			curr->next = next->next;
			gc_free(next, head);
		}
		else
			curr = curr->next;
	}
	return (0);
}
