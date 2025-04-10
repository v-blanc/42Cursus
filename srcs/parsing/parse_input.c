#include "../../include/minishell.h"

static int	sub_parse_input(char *input, char ***cmd_args, int i,
		int *quote_flag, t_garbage_collector **head)
{
	int	len_input;

	if (input[i] == '"' || input[i] == '\'')
	{
		if ((*quote_flag) == 0)
			(*quote_flag) = input[i];
		else if ((*quote_flag) == input[i])
			(*quote_flag) = 0;
	}
	else if (input[i] == ' ' && (*quote_flag) == 0)
	{
		len_input = ft_strlen(input);
		(*cmd_args)[0] = gc_malloc(i * sizeof(char) + 1, head);
		(*cmd_args)[1] = gc_malloc((len_input - i) * sizeof(char) + 1, head);
		if (!(*cmd_args)[0] || !(*cmd_args)[1])
			return (1);
		ft_strlcpy((*cmd_args)[0], input, i + 1);
		ft_strlcpy((*cmd_args)[1], input + i + 1, len_input - i);
		return (-1);
	}
	return (0);
}

int	parse_input(char *input, char ***cmd_args, t_garbage_collector **head)
{
	int	i;
	int	ret_val;
	int	quote_flag;

	(*cmd_args) = (char **)gc_malloc_array(2 * sizeof(char *), head);
	if (!(*cmd_args))
		return (1);
	quote_flag = 0;
	i = 0;
	while (input[i])
	{
		ret_val = sub_parse_input(input, cmd_args, i, &quote_flag, head);
		if (ret_val == -1)
			break ;
		else if (ret_val == 1)
			return (1);
		i++;
	}
	if (!input[i] && (*cmd_args)[0] == NULL)
	{
		(*cmd_args)[0] = gc_malloc(i * sizeof(char) + 1, head);
		if (!(*cmd_args)[0])
			return (1);
		ft_strlcpy((*cmd_args)[0], input, i + 1);
	}
	return (0);
}

int	testing_input(char *input, t_garbage_collector **head)
{
	char	**cmd_args;

	cmd_args = NULL;
	if (parse_input(input, &cmd_args, head))
		return (1);
	if (!cmd_args[0])
		return (1);
	printf("\ncmd:\n>>>%s<<<\nargs:\n>>>%s<<<\n\n", cmd_args[0], cmd_args[1]);
	gc_free_array(cmd_args, head);
	return (0);
}

// typedef struct s_redirect
// {
// 	int					type;
// 	char				*filename;
// 	struct s_redirect	*next;
// }						t_redirect;

// typedef struct s_cli
// {
// 	char				*cmd;
// 	char				*args;
// 	t_redirect			*redirects;
// 	struct s_cli		*next;
// }						t_cli;

// typedef struct s_cli_tree
// {
// 	int					type;
// 	char				*cmd;
// 	char				*args;
// 	struct s_cli_tree	*left;
// 	struct s_cli_tree	*right;
// }						t_cli_tree;
