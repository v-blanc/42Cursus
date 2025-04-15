#include "minishell.h"

char	*gc_strndup(const char *s, size_t n, t_gc **head)
{
	size_t	i;
	char	*dup;

	dup = gc_malloc(n + 1, head);
	if (!dup)
		return (NULL);
	i = 0;
	while (i < n && s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
