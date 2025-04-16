#include "minishell.h"

void	*gc_malloc(size_t size, t_gc **head)
{
	t_gc	*new;

	new = malloc(sizeof(t_gc));
	if (!new)
	{
		print(2, "malloc: %s\n", strerror(errno));
		return (NULL);
	}
	new->perm = 0;
	new->mem = ft_calloc(1, size);
	if (!new->mem)
	{
		print(2, "malloc: %s\n", strerror(errno));
		free(new);
		return (NULL);
	}
	new->next = *head;
	*head = new;
	return (new->mem);
}

void	**gc_malloc_array(size_t size, t_gc **head)
{
	void	**array;

	array = gc_malloc((size + 1) * sizeof(void *), head);
	if (!array)
		return (NULL);
	array[size] = NULL;
	return (array);
}

void	*gc_malloc_perm(size_t size, t_gc **head)
{
	t_gc	*new;

	new = malloc(sizeof(t_gc));
	if (!new)
	{
		print(2, "malloc: %s\n", strerror(errno));
		return (NULL);
	}
	new->perm = 1;
	new->mem = ft_calloc(1, size);
	if (!new->mem)
	{
		print(2, "malloc: %s\n", strerror(errno));
		free(new);
		return (NULL);
	}
	new->next = *head;
	*head = new;
	return (new->mem);
}

void	**gc_malloc_array_perm(size_t size, t_gc **head)
{
	void	**array;

	array = gc_malloc_perm((size + 1) * sizeof(void *), head);
	if (!array)
		return (NULL);
	array[size] = NULL;
	return (array);
}
