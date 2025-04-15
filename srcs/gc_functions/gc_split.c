#include "minishell.h"

static int	ft_count_words(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static int	gc_sub_split(char const *s, char c, char **tab, t_gc **head)
{
	char	*new_s;
	int		i;

	i = 0;
	while (*s)
	{
		new_s = (char *)s;
		while (*new_s && *new_s != c)
			new_s++;
		if (new_s - s > 0)
		{
			tab[i++] = gc_substr(s, 0, new_s - s, head);
			if (tab[i - 1] == NULL)
				return (1);
		}
		if (!*new_s)
			break ;
		s = new_s + 1;
	}
	tab[i] = NULL;
	return (0);
}

/* Allocates (with malloc(3)) and returns an array of strings obtained
by splitting ’s’ using the character ’c’ as a delimiter.
The array is NULL-terminated. */
char	**gc_split(char const *s, char c, t_gc **head)
{
	char	**tab;

	if (!s)
		return (NULL);
	tab = (char **)gc_malloc(sizeof(char *) * (ft_count_words(s, c) + 1), head);
	if (!tab)
		return (NULL);
	if (gc_sub_split(s, c, tab, head))
		return (NULL);
	return (tab);
}
