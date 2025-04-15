#include "minishell.h"

static int	is_valid_var_char(char c, int pos)
{
	if (pos == 0)
		return (isalpha(c) || c == '_');
	return (isalnum(c) || c == '_');
}

static int	sub_get_expand_len(char *word, int *i, int *len, t_context *context)
{
	int		start;
	char	*var_name;
	char	*val;

	(*i)++;
	start = (*i);
	while (is_valid_var_char(word[(*i)], (*i)))
		(*i)++;
	var_name = gc_strndup(&word[start], (*i) - start, context->head);
	if (!var_name)
		return (1);
	if (*i == start && word[(*i)] == '?')
		(*len) += ft_intlen(context->last_exit_status);
	else if (*i == start && word[(*i)] == '$')
		(*len) += ft_intlen(getpid());
	else
	{
		val = getenv(var_name);
		if (val)
			(*len) += ft_strlen(val);
	}
	gc_free(var_name, context->head);
	return (0);
}

static int	get_expand_len(char *word, t_context *context)
{
	int	i;
	int	len;

	i = 0;
	len = 1;
	while (word[i])
	{
		if (word[i] == '$' && word[i + 1])
		{
			if (isdigit(word[i + 1]))
			{
				i += 2;
				len += ft_strlen(getenv(&word[i]));
			}
			else if (sub_get_expand_len(word, &i, &len, context))
				return (-1);
		}
		else
		{
			len++;
			i++;
		}
	}
	return (len);
}

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
	int		len_value_expanded;

	cur = *tokens;
	while (cur)
	{
		if (cur->type == WORD && cur->quote != SINGLE_QUOTE && cur->value)
		{
			if (expand_tilde(&cur->value, head))
				return (1);
			len_value_expanded = get_expand_len(cur->value, context);
			if (len_value_expanded < 0)
				return (1);
			if (expand_one_token(&cur->value, len_value_expanded, context,
					head))
				return (1);
		}
		cur = cur->next;
	}
	return (0);
}
