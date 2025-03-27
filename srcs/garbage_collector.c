#include "../include/minishell.h"

void	*gc_malloc(size_t size, t_garbage_collector **head)
{
	t_garbage_collector	*new;

	new = malloc(sizeof(t_garbage_collector));
	new->mem = malloc(size);
	new->next = *head;
	*head = new;
	return (new->mem);
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

void	gc_free_all(t_garbage_collector *head)
{
	if (head == NULL)
		return ;
	gc_free_all(head->next);
	free(head->mem);
	free(head);
}

int	main(void)
{
	t_garbage_collector	*head;
	char				**str;
	char				*test;
	char				*blabla;

	head = NULL;
	blabla = gc_malloc(10, &head);
	str = gc_malloc(10, &head);
	for (int i = 0; i < 10; i++)
		str[i] = gc_malloc(20, &head);
	// for(int i = 0; i < 10; i++)
	test = gc_malloc(10, &head);
	gc_free_all(head);
	return (0);
}
