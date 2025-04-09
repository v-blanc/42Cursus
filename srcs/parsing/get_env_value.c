#include "../../include/minishell.h"

static int	found_value(char **input_with_env, char *input_str, int *ind,
		t_garbage_collector **head)
{
	char	*value;
	char	*name;
	char	*var_env;

	value = NULL;
	if (!ft_strncmp(&input_str[ind[0]], "$$", 2))
		value = ft_itoa(getpid());
	else if (!ft_strncmp(&input_str[ind[0]], "$?", 2))
		value = "9999999"; // TODO: get exit status
	else
	{
		(void)head;
		name = ft_substr(input_str, ind[0] + 1, ind[1] - ind[0] - 1);
		if (!name)
			return (1);
		var_env = getenv(name);
		if (var_env)
			value = var_env;
		else
			value = "";
	}
	ft_strlcat((*input_with_env), value, ft_strlen((*input_with_env))
		+ ft_strlen(value) + 1);
	return (0);
}

static void	detect_var(char **input_with_env, char *input_str, int *ind, int *i)
{
	while (input_str[ind[0]] && ft_strncmp(&input_str[ind[0]], "$", 1))
		(*input_with_env)[(*i)++] = input_str[ind[0]++];
	if (!input_str[ind[0]])
		return ;
	ind[1] = ind[0] + 1;
	while (input_str[ind[1]] && ft_isalnum(input_str[ind[1]]))
		ind[1]++;
	if (ind[1] == ind[0] + 1 && input_str[ind[0]] == '$'
		&& input_str[ind[1]] != '$' && input_str[ind[1]] != '?')
		(*input_with_env)[(*i)++] = '$';
}

int	get_env_value(char **input_with_env, char *input_str,
		t_garbage_collector **head)
{
	int	i;
	int	ind[2];

	// TODO: fix the size `10000`?
	(*input_with_env) = gc_malloc(sizeof(char) * 10000, head);
	if (!(*input_with_env))
		return (1);
	i = 0;
	ind[0] = 0;
	while (input_str[ind[0]])
	{
		detect_var(input_with_env, input_str, ind, &i);
		if (!input_str[ind[0]])
			return (0);
		if (found_value(input_with_env, input_str, ind, head))
			return (1);
		if (!ft_strncmp(&input_str[ind[0]], "$$", 2)
			|| !ft_strncmp(&input_str[ind[0]], "$?", 2))
			ind[1]++;
		ind[0] = ind[1];
		i = ft_strlen((*input_with_env));
	}
	return (0);
}

// int	testing_parsing(char *input_str, t_garbage_collector **head)
// {
// 	char	*input_with_env;

// 	input_with_env = NULL;
// 	if (get_env_value(&input_with_env, input_str, head))
// 		return (1);
// 	printf("\n>>>> %s\n\n", input_with_env);
// 	return (0);
// }
