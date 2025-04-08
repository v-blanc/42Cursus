#include "../../include/minishell.h"

void	init_stack(t_stack *stack)
{
	ft_memset(stack->data, 0, QUOTES_MAX);
	stack->top = -1;
}

int	is_stack_empty(t_stack *stack)
{
	return (stack->top == -1);
}

int	push_stack(t_stack *stack, char c)
{
	if (stack->top == QUOTES_MAX - 1)
		return (1);
	stack->data[++stack->top] = c;
	return (0);
}

char	pop_stack(t_stack *stack)
{
	if (is_stack_empty(stack))
		return (0);
	return (stack->data[stack->top--]);
}

char	top_stack(t_stack *stack)
{
	if (is_stack_empty(stack))
		return (0);
	return (stack->data[stack->top]);
}
