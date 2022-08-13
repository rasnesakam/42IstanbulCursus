#include "../stack/stack.h"
#include "../verbs/verbs.h"
#include <libft.h>

void ft_rotpos(t_stack *stack, int pos, char *stack_name)
{
	if (pos > (stack->top / 2))
	{
		pos = stack->top + 1 - pos;
		while (pos--)
		{
			revr(stack);
			ft_putendl_fd(ft_strjoin("rr", stack_name), 1);
		}
	}
	else
	{
		while (pos--)
		{
			rotate(stack);
			ft_putendl_fd(ft_strjoin("r", stack_name), 1);
		}
	}
}

void	ft_rotate_mutual(t_stack *stack_a, int *pos_a, t_stack *stack_b, int *pos_b)
{
	// Rotate
	if (*pos_a <= (stack_a->top + 1) / 2 && *pos_b < (stack_b->top + 1) / 2)
	{
		while (*pos_a > 0 && *pos_b > 0)
		{
			rrotate(stack_a, stack_b);
			ft_putendl_fd("rr", 1);
			(*pos_a)--;
			(*pos_b)--;
		}
	}
	// Reverse Rotate
	else if (*pos_a > (stack_a->top + 1) / 2 && *pos_b > (stack_b->top + 1) / 2)
	{
		while (*pos_a < (stack_a->top + 1) && *pos_b < (stack_b->top + 1))
		{
			revrr(stack_a, stack_b);
			ft_putendl_fd("rrr", 1);
			(*pos_a)++;
			(*pos_b)++;
		}
		if (*pos_a >= (stack_a->top + 1))
			*pos_a -= (stack_a->top + 1);
		if (*pos_b >= (stack_b->top + 1))
			*pos_b -= (stack_b->top + 1);
	}
}

void ft_rotate_stacks(t_stack *stack_a, int pos_a, t_stack *stack_b, int pos_b)
{

// MUTUAL ROTATION
ft_rotate_mutual(stack_a, &pos_a, stack_b, &pos_b);
ft_rotpos(stack_a, pos_a, "a");
ft_rotpos(stack_b, pos_b, "b");

}