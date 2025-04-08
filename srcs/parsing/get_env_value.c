#include "../../include/minishell.h"

int	get_env_value(char **input_with_env, char *input_str,
		t_garbage_collector **head)
{
	char	*value;
	char	*name;
	char	*var_env;
	int		i;
	int		j;
	int		a;

	(*input_with_env) = gc_malloc(sizeof(char) * 10000, head);
	if (!(*input_with_env))
		return (1);
	a = 0;
	i = 0;
	while (input_str[a])
	{
		value = NULL;
		printf("input_with_env: '%s'\n", (*input_with_env));
		while (input_str[a] && ft_strncmp(&input_str[a], "$", 1))
			(*input_with_env)[i++] = input_str[a++];
		if (!input_str[a])
			return (0);
		j = a + 1;
		while (input_str[j] && ft_isalnum(input_str[j]))
			j++;
		if (!ft_strncmp(&input_str[a], "$$", 2))
			value = ft_itoa(getpid());
		else if (!ft_strncmp(&input_str[a], "$?", 2))
			value = "100000"; // TODO: get exit status
		else
		{
			name = &input_str[a + 1];
			name[j - a - 1] = '\0';
			var_env = getenv(name);
			if (var_env)
				value = var_env;
			else
				value = "";
		}
		printf("input_with_env: '%s'\n", (*input_with_env));
		printf("value: '%s'\n", value);
		// Add 'value' at the end of input_with_env
		ft_strlcat((*input_with_env), value, ft_strlen((*input_with_env))
			+ ft_strlen(value) + 1);
		printf("input_with_env: '%s'\n", (*input_with_env));
		printf("a= %d, i= %d, j= %d\n", a, i, j);
		a = j;
		i = ft_strlen((*input_with_env)) + 1;
		if (value[0] == '\0')
		{
			a++;
			i++;
		}
	}
	return (0);
}

int	testing_parsing(char *input_str, t_garbage_collector **head)
{
	char	*input_with_env;

	input_with_env = NULL;
	if (get_env_value(&input_with_env, input_str, head))
		return (1);
	printf("\n\n>>>> %s\n", input_with_env);
	return (0);
}
