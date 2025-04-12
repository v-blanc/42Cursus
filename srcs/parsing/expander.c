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

// int	main(int argc, char **argv)
// {
// 	t_context	*context;
// 	t_gc		*head;
// 	t_token		*token_head;
// 	t_token		*tokens;

// 	if (argc != 2)
// 		return (1);
// 	head = NULL;
// 	context = gc_malloc(sizeof(t_context), &head);
// 	if (!context)
// 		return (1);
// 	context->argc = argc;
// 	context->argv = argv;
// 	context->last_exit_status = 22222;
// 	context->head = &head;
// 	//
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
// 	if (expander(&tokens, context, &head))
// 		return (1);
// 	while (tokens)
// 	{
// 		printf("Expanded: type=%d, value=`%s`\n", tokens->type, tokens->value);
// 		tokens = tokens->next;
// 	}
// 	gc_free_all(head);
// 	return (0);
// }
