#include "../../include/minishell.h"

char	*gc_substr(char const *s, unsigned int start, size_t len,
		t_garbage_collector **head)
{
	char	*sub;
	size_t	len_s;

	len_s = ft_strlen(s);
	if (len_s - start < len)
		len = len_s - start;
	if (start > len_s)
		return (gc_strdup("", head));
	sub = (char *)gc_malloc(sizeof(char) * len + 1, head);
	if (!sub)
		return (NULL);
	ft_memcpy(sub, s + start, len);
	sub[len] = '\0';
	return (sub);
}
