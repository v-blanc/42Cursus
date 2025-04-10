#include "../../include/minishell.h"

void	*gc_malloc(size_t size, t_garbage_collector **head)
{
	t_garbage_collector	*new;

	new = malloc(sizeof(t_garbage_collector));
	if (!new)
	{
		printf("malloc error\n");
		return (NULL);
	}
	new->mem = ft_calloc(1, size);
	if (!new->mem)
	{
		printf("malloc error\n");
		free(new);
		return (NULL);
	}
	new->next = *head;
	*head = new;
	return (new->mem);
}

void	**gc_malloc_array(size_t size, t_garbage_collector **head)
{
	void	**array;

	array = gc_malloc((size + 1) * sizeof(void *), head);
	if (!array)
		return (NULL);
	array[size] = NULL;
	return (array);
}

void	gc_free(void *mem, t_garbage_collector **head)
{
	t_garbage_collector	*tmp;

	if ((*head)->mem == mem)
	{
		tmp = (*head)->next;
		free((*head)->mem);
		free(*head);
		*head = tmp;
	}
	else
	{
		tmp = *head;
		while (tmp)
		{
			if (tmp->mem == mem)
			{
				(*head)->next = tmp->next;
				free(tmp->mem);
				free(tmp);
				break ;
			}
			tmp = tmp->next;
		}
	}
}

void	gc_free_array(char **array, t_garbage_collector **head)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	while (--i >= 0)
		gc_free(array[i], head);
	gc_free(array, head);
}

void	gc_free_all(t_garbage_collector *head)
{
	if (head == NULL)
		return ;
	gc_free_all(head->next);
	free(head->mem);
	free(head);
}
