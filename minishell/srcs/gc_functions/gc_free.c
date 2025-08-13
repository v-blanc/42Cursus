/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 19:20:01 by vblanc            #+#    #+#             */
/*   Updated: 2025/05/18 12:47:41 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gc_functions.h"

void	gc_free(void *mem, t_gc **head)
{
	t_gc	*tmp;

	if (head && *head && (*head)->mem == mem)
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

void	gc_free_all(t_gc **head)
{
	t_gc	*curr;
	t_gc	*prev;
	t_gc	*next;

	curr = *head;
	prev = NULL;
	while (curr)
	{
		next = curr->next;
		if (curr->perm == 0)
		{
			if (prev)
				prev->next = next;
			else
				*head = next;
			free(curr->mem);
			free(curr);
		}
		else
			prev = curr;
		curr = next;
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
