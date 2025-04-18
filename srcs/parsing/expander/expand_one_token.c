#include "minishell.h"

static int	is_valid_var_char(char c, int pos)
{
	if (pos == 0)
		return (isalpha(c) || c == '_' || c == '*');
	return (isalnum(c) || c == '_' || c == '*');
}

static int	special_case(const char *word, char *result, int *ind,
		t_context *context)
{
	char	*val;
	int		i;
	int		pid;

	val = NULL;
	if (word[ind[0]] == '?')
		val = gc_itoa(context->last_exit_status, context->head);
	else if (word[ind[0]] == '$')
	{
		pid = getpid();
		if (pid < 0)
			return (1);
		val = gc_itoa(pid, context->head);
	}
	if (!val)
		return (1);
	i = 0;
	while (val[i])
		result[ind[1]++] = val[i++];
	gc_free(val, context->head);
	ind[0]++;
	return (0);
}

static int	sub_expand_one_var(const char *word, char *result, int *ind,
		t_context *context)
{
	int		start;
	int		len;
	char	*var_name;
	char	*val;

	start = ++ind[0];
	if (word[ind[0]] && (word[ind[0]] == '$' || word[ind[0]] == '?'))
		return (special_case(word, result, ind, context));
	len = 0;
	while (is_valid_var_char(word[ind[0]], len))
	{
		ind[0]++;
		len++;
	}
	var_name = gc_strndup(&word[start], len, context->head);
	if (!var_name)
		return (1);
	val = getenv(var_name);
	gc_free(var_name, context->head);
	if (!val)
		return (0);
	while (*val)
		result[ind[1]++] = *val++;
	return (0);
}

static void	positional_var(const char *word, t_context *context, char *result,
		int *ind)
{
	int	i;
	int	nb;

	ind[0]++;
	nb = ft_atoi(&word[ind[0]]);
	if (nb > context->argc - 1)
	{
		ind[0]++;
		return ;
	}
	i = 0;
	while (context->argv[nb][i])
		result[ind[1]++] = context->argv[nb][i++];
	ind[0]++;
	return ;
}

int	expand_one_token(char **w, int len_w, t_context *ctx)
{
	char	*result;
	int		ind[2];

	result = gc_malloc(len_w, ctx->head);
	if (!result)
		return (1);
	ind[0] = 0;
	ind[1] = 0;
	while ((*w)[ind[0]])
	{
		if ((*w)[ind[0]] == '$' && (*w)[ind[0] + 1] && ft_isalnum((*w)[ind[0]
				+ 1]))
		{
			if (isdigit((*w)[ind[0] + 1]))
				positional_var((*w), ctx, result, ind);
			else if (sub_expand_one_var((*w), result, ind, ctx))
				return (1);
		}
		else
			result[ind[1]++] = (*w)[ind[0]++];
	}
	result[ind[1]] = '\0';
	gc_free(w, ctx->head);
	(*w) = result;
	return (0);
}
