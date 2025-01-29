/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 20:02:50 by vblanc            #+#    #+#             */
/*   Updated: 2025/01/29 12:43:03 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/* Libraries */

# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

/* Structures */

typedef struct s_stack
{
	int	*data;
	int	top;
	int	capacity;
}		t_stack;

/* stack.c */

t_stack	*init_stack(int capacity);
t_stack	*fill_stack(int capacity, int *data);
void	free_stack(t_stack *stack);
int		is_empty(t_stack *stack);

/* rules_utils.c */

void	ft_swap(t_stack *stack);
void	ft_push(t_stack *first_stack, t_stack *second_stack);
void	ft_rotate(t_stack *stack);
void	ft_reverse_rotate(t_stack *stack);

/* rules.c */

void	ft_rules_push(t_stack *stack_a, t_stack *stack_b, char *rule);
void	ft_rules_swap(t_stack *stack_a, t_stack *stack_b, char *rule);
void	ft_rules_rotate(t_stack *stack_a, t_stack *stack_b, char *rule);
void	ft_rules_reverse_rotate(t_stack *stack_a, t_stack *stack_b, char *rule);
void	ft_rules(t_stack *stack_a, t_stack *stack_b, char *rule);

/* parse.c */

void	ft_get_indexes(int *number, char **input, int **indexes);

/* sort.c */

void	ft_manual_sort(t_stack *stack_a, t_stack *stack_b);
void	ft_sort(t_stack *stack_a, t_stack *stack_b);

#endif
