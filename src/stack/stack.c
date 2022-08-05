
#include "stack.h"
#include "../utils/utils.h"

t_stack *create_stack(int size)
{
	t_stack *stack;
	int		*datas;

	stack = malloc(sizeof(t_stack));
	datas = malloc(sizeof(int) * size);
	if (stack == NULL || datas == NULL)
		return (NULL);
	stack->size = size;
	stack->datas = datas;
	stack->top = 0;
	return (stack);
}

void	destroy_stack(t_stack *stack)
{
	free(stack->datas);
	free(stack);
}

void	push_stack(t_stack *stack, int value)
{
	if (stack->top < stack->size)
	{
		stack->top += 1;
		stack->datas[stack->top] = value;
	}
	else
		ft_error("STACK OVERFLOW");
}

int	pop_stack(t_stack *stack)
{
	if (stack->top > 0)
	{
		stack->top -= 1;
		return (stack->datas[stack->top + 1]);
	}
	else
		ft_error("STACK IS EMPTY");
}