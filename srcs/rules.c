/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 13:58:05 by vblanc            #+#    #+#             */
/*   Updated: 2024/11/21 23:40:24 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_rules_swap(t_stack *stack_a, t_stack *stack_b, char *rule)
{
	if (ft_strncmp(rule, "sa", 2) == 0)
	{
		printf("sa\n");
		ft_swap(stack_a);
	}
	else if (ft_strncmp(rule, "sb", 2) == 0)
	{
		printf("sb\n");
		ft_swap(stack_b);
	}
	else if (ft_strncmp(rule, "ss", 2) == 0)
	{
		printf("ss\n");
		ft_swap(stack_a);
		ft_swap(stack_b);
	}
}

void	ft_rules_push(t_stack *stack_a, t_stack *stack_b, char *rule)
{
	if (ft_strncmp(rule, "pa", 2) == 0)
	{
		printf("pa\n");
		ft_push(stack_a, stack_b);
	}
	else if (ft_strncmp(rule, "pb", 2) == 0)
	{
		printf("pb\n");
		ft_push(stack_b, stack_a);
	}
}

void	ft_rules_rotate(t_stack *stack_a, t_stack *stack_b, char *rule)
{
	if (ft_strncmp(rule, "ra", 2) == 0)
	{
		printf("ra\n");
		ft_rotate(stack_a);
	}
	else if (ft_strncmp(rule, "rb", 2) == 0)
	{
		printf("rb\n");
		ft_rotate(stack_b);
	}
	else if (ft_strncmp(rule, "rr", 2) == 0)
	{
		printf("rr\n");
		ft_rotate(stack_a);
		ft_rotate(stack_b);
	}
}

void	ft_rules_reverse_rotate(t_stack *stack_a, t_stack *stack_b, char *rule)
{
	if (ft_strncmp(rule, "rra", 3) == 0)
	{
		printf("rra\n");
		ft_reverse_rotate(stack_a);
	}
	else if (ft_strncmp(rule, "rrb", 3) == 0)
	{
		printf("rrb\n");
		ft_reverse_rotate(stack_b);
	}
	else if (ft_strncmp(rule, "rrr", 3) == 0)
	{
		printf("rrr\n");
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
