#include "../../include/minishell.h"

extern char	**environ;

// static void	found_env_value(char *name, char **value)
// {
// 	int	i;

// 	i = 0;
// 	while (environ[i])
// 	{
// 		if (!ft_strncmp(environ[i], name, ft_strlen(name)))
// 		{
// 			*value = environ[i] + ft_strlen(name) + 1;
// 			return ;
// 		}
// 		i++;
// 	}
// }

// int	get_env_value(char ***input, char *input_str,
// t_garbage_collector **head)
// {
// 	char	*value;
// 	int		i;

// 	(*input) = gc_split(input_str, ' ', head);
// 	if (!(*input))
// 		return (1);
// 	i = 0;
// 	while ((*input)[i])
// 	{
// 		value = NULL;

// 		i++;
// 	}
// 	return (0);
// }

// int	testing_parsing(char *input_str, t_garbage_collector **head)
// {
// 	char	**input;

// 	input = NULL;
// 	if (get_env_value(&input, input_str, head))
// 		return (1);
// 	printf("\n\n>>>>");
// 	for (int i = 0; input[i]; i++)
// 		printf("%s ", input[i]);
// 	printf("\n");
// 	return (0);
// }
