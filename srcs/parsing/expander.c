#include "../../include/minishell.h"

static int	is_valid_var_char(char c, int pos)
{
	if (pos == 0)
		return (isalpha(c) || c == '_');
	return (isalnum(c) || c == '_');
}

static int	special_case(const char *word, char *result, int *ind, t_gc **head)
{
	char	*val;
	int		i;

	if (word[ind[0]] == '?')
		val = ft_itoa(99999); // TODO: gc_itoa and change to $?
	else if (word[ind[0]] == '$')
		val = ft_itoa(getpid()); // TODO: gc_itoa
	if (!val)
		return (1);
	i = 0;
	while (val[i])
		result[ind[1]++] = val[i++];
	(void)head;
	free(val);
	// gc_free(val, head);
	ind[0]++;
	return (0);
}

static int	sub_expand_one_var(const char *word, char *result, int *ind,
		t_gc **head)
{
	int		start;
	int		len;
	char	*var_name;
	char	*val;

	start = ++ind[0];
	if (word[ind[0]] && (word[ind[0]] == '$' || word[ind[0]] == '?'))
		return (special_case(word, result, ind, head));
	len = 0;
	while (is_valid_var_char(word[ind[0]], len))
	{
		ind[0]++;
		len++;
	}
	var_name = strndup(&word[start], len); // TODO: add gc_strndup
	if (!var_name)
		return (1);
	val = getenv(var_name);
	free(var_name);
	while (*val)
		result[ind[1]++] = *val++;
	return (0);
}

static int	expand_one_var(char **word, t_gc **head)
{
	char	*result;
	int		ind[2];

	// TODO: calculate size
	result = gc_malloc(ft_strlen(*word) * 10 + 1, head);
	if (!result)
		return (1);
	ind[0] = 0;
	ind[1] = 0;
	while ((*word)[ind[0]])
	{
		if ((*word)[ind[0]] == '$' && (*word)[ind[0] + 1] && (*word)[ind[0]
			+ 1] != ' ')
		{
			if (sub_expand_one_var((*word), result, ind, head))
				return (1);
		}
		else
			result[ind[1]++] = (*word)[ind[0]++];
	}
	result[ind[1]] = '\0';
	gc_free(word, head);
	(*word) = result;
	return (0);
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

int	expander(t_token **tokens, t_gc **head)
{
	t_token	*cur;

	cur = *tokens;
	while (cur)
	{
		if (cur->type == WORD && cur->quote != SINGLE_QUOTE)
		{
			if (expand_tilde(&cur->value, head))
				return (1);
			if (expand_one_var(&cur->value, head))
				return (1);
		}
		cur = cur->next;
	}
	return (0);
}

// int	main(int argc, char **argv)
// {
// 	t_gc	*head;
// 	t_token	*token_head;
// 	t_token	*tokens;

// 	if (argc != 2)
// 		return (1);
// 	head = NULL;
// 	token_head = NULL;
// 	tokens = NULL;
// 	printf("input: %s\n", argv[1]);
// 	if (tokenizer(&tokens, argv[1], &head))
// 		return (1);
// 	token_head = tokens;
// 	while (tokens)
// 	{
// 		printf("Token: type=%d, quote=%d, joined_next=%d, value=`%s`\n",
// 			tokens->type, tokens->quote, tokens->joined_next, tokens->value);
// 		tokens = tokens->next;
// 	}
// 	tokens = token_head;
// 	if (expander(&tokens, &head))
// 		return (1);
// 	while (tokens)
// 	{
// 		printf("Expanded: type=%d, value=`%s`\n", tokens->type, tokens->value);
// 		tokens = tokens->next;
// 	}
// 	gc_free_all(head);
// 	return (0);
// }
