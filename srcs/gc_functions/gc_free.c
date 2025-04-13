#include "../../include/minishell.h"

void	gc_free(void *mem, t_gc **head)
{
	t_gc	*tmp;

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

void	gc_free_array(char **array, t_gc **head)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	while (--i >= 0)
		gc_free(array[i], head);
	gc_free(array, head);
}

void	gc_free_all(t_gc *head)
{
	if (head == NULL)
		return ;
	gc_free_all(head->next);
	if (head->perm == 0)
	{
		free(head->mem);
		free(head);
	}
}

void	gc_free_all_perm(t_gc *head)
{
	if (head == NULL)
		return ;
	gc_free_all_perm(head->next);
	free(head->mem);
	free(head);
}
