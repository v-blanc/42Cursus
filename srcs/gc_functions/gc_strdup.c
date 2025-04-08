#include "../../include/minishell.h"

char	*gc_strdup(const char *s, t_garbage_collector **head)
{
	char	*d;
	size_t	len;

	len = ft_strlen(s) + 1;
	d = (char *)gc_malloc(sizeof(char) * len, head);
	if (!d)
		return (NULL);
	ft_memcpy(d, s, len);
	return (d);
}
