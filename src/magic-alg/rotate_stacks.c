#include "../stack/stack.h"
#include "../verbs/verbs.h"
#include "../magic-alg/magic-alg.h"
#include "../data-analyzer/data-analyzer.h"
#include <libft.h>

static void	ft_rotate_mutual(t_stack *stack_a, int *pos_a, t_stack *stack_b, int *pos_b)
{
	// Rotate
	if (*pos_a < (stack_a->top + 1) / 2 && *pos_b < (stack_b->top + 1) / 2)
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
	else if (*pos_a >= (stack_a->top + 1) / 2 && *pos_b >= (stack_b->top + 1) / 2)
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

void ft_rotpos(t_stack *stack, int pos, char *stack_name)
{
	char *name;

	if (pos > (stack->top / 2))
	{
		pos = stack->top + 1 - pos;
		while (pos-- > 0)
		{
			revr(stack);
			name = ft_strjoin("rr", stack_name);
			ft_putendl_fd(name, 1);
			free(name);
		}
	}
	else
	{
		while (pos-- > 0)
		{
			rotate(stack);
			name = ft_strjoin("r", stack_name);
			ft_putendl_fd(name, 1);
			free(name);
		}
	}
}

#include <stdio.h>
void ft_rotate_stacks(t_stack *stack_a, int pos_a, t_stack *stack_b, int pos_b)
{

// MUTUAL ROTATION
if (stack_a->top > 0 && stack_b->top > 0)
	ft_rotate_mutual(stack_a, &pos_a, stack_b, &pos_b); // rotate if both stack sizes bigger than 1
if (stack_a->top > 0) // rotate if a stack size bigger than 1
	ft_rotpos(stack_a, pos_a, "a");
if (stack_b->top > 0) // rotate if b stack size bigger than 1
	ft_rotpos(stack_b, pos_b, "b");

}

void	ft_sort_rotate(t_stack *stack)
{
	int	posmax;
	int	posmin;

	posmax = find_pos(*stack, get_max(*stack), NULL);
	posmin = find_pos(*stack, get_min(*stack), NULL);
	if (posmin - posmax == 1)
	{
		if (posmax > 0)
		{
			revr(stack);
			ft_putendl_fd("rra", 1);
		}
		else
		{
			rotate(stack);
			ft_putendl_fd("ra", 1);
		}
	}
	else
	{
		swap(stack);
		ft_putendl_fd("sa", 1);
	}
	if (check_sorted(*stack) == 0)
		ft_sort_rotate(stack);
}
