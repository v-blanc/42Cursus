/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 13:58:05 by vblanc            #+#    #+#             */
/*   Updated: 2025/02/07 16:11:52 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_rules_swap(t_stack *stack_a, t_stack *stack_b, char *rule)
{
	if (ft_strncmp(rule, "sa", 2) == 0)
	{
		write(1, "sa\n", 3);
		ft_swap(stack_a);
	}
	else if (ft_strncmp(rule, "sb", 2) == 0)
	{
		write(1, "sb\n", 3);
		ft_swap(stack_b);
	}
	else if (ft_strncmp(rule, "ss", 2) == 0)
	{
		write(1, "ss\n", 3);
		ft_swap(stack_a);
		ft_swap(stack_b);
	}
}

void	ft_rules_push(t_stack *stack_a, t_stack *stack_b, char *rule)
{
	if (ft_strncmp(rule, "pa", 2) == 0)
	{
		write(1, "pa\n", 3);
		ft_push(stack_a, stack_b);
	}
	else if (ft_strncmp(rule, "pb", 2) == 0)
	{
		write(1, "pb\n", 3);
		ft_push(stack_b, stack_a);
	}
}

void	ft_rules_rotate(t_stack *stack_a, t_stack *stack_b, char *rule)
{
	if (ft_strncmp(rule, "ra", 2) == 0)
	{
		write(1, "ra\n", 3);
		ft_rotate(stack_a);
	}
	else if (ft_strncmp(rule, "rb", 2) == 0)
	{
		write(1, "ra\n", 3);
		ft_rotate(stack_b);
	}
	else if (ft_strncmp(rule, "rr", 2) == 0)
	{
		write(1, "rr\n", 3);
		ft_rotate(stack_a);
		ft_rotate(stack_b);
	}
}

void	ft_rules_reverse_rotate(t_stack *stack_a, t_stack *stack_b, char *rule)
{
	if (ft_strncmp(rule, "rra", 3) == 0)
	{
		write(1, "rra\n", 4);
		ft_reverse_rotate(stack_a);
	}
	else if (ft_strncmp(rule, "rrb", 3) == 0)
	{
		write(1, "rrb\n", 4);
		ft_reverse_rotate(stack_b);
	}
	else if (ft_strncmp(rule, "rrr", 3) == 0)
	{
		write(1, "rrr\n", 4);
		ft_reverse_rotate(stack_a);
		ft_reverse_rotate(stack_b);
	}
}

void	ft_rules(t_stack *stack_a, t_stack *stack_b, char *rule)
{
	if (ft_strncmp(rule, "s", 1) == 0)
		ft_rules_swap(stack_a, stack_b, rule);
	else if (ft_strncmp(rule, "p", 1) == 0)
		ft_rules_push(stack_a, stack_b, rule);
	else if (ft_strncmp(rule, "r", 1) == 0 && ft_strlen(rule) == 2)
		ft_rules_rotate(stack_a, stack_b, rule);
	else
		ft_rules_reverse_rotate(stack_a, stack_b, rule);
}
