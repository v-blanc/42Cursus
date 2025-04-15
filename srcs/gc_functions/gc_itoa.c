#include "minishell.h"

char	*gc_itoa(int n, t_gc **head)
{
	char	*str;
	int		i;

	if (n == -2147483648)
		return (gc_strdup("-2147483648", head));
	str = gc_malloc(sizeof(char) * ft_intlen(n) + 1, head);
	if (!str)
		return (NULL);
	i = ft_intlen(n);
	str[i--] = '\0';
	if (n < 0)
		str[0] = '-';
	n = ((n > 0) - (n < 0)) * n;
	while (n > 9)
	{
		str[i--] = (n % 10) + '0';
		n = n / 10;
	}
	str[i] = n + '0';
	return (str);
}
