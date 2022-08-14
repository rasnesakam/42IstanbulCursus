#include "../stack/stack.h"
#include "../data-analyzer/data-analyzer.h"
#include "../verbs/verbs.h"
#include "magic-alg.h"
#include <libft.h>

/**
 * transfer if less than
 */
static void	ft_tiflt(t_stack *stack_a, int filter, t_stack *stack_b)
{
	int	count;
	int	limit;

	count = 0;
	limit = stack_a->top;
	while (count++ <= limit)
	{
		if (top_stack(stack_a) <= filter)
		{
			ft_putendl_fd("pb", 1);
			push(stack_a, stack_b);
		}
		else
		{
			ft_putendl_fd("ra", 1);
			rotate(stack_a);
		}
	}
}

static void	ft_filter(t_stack *stack_a, t_stack *stack_b)
{
	int	avg;

	while (stack_a->top >= 2)
	{
		avg = get_avg(*stack_a);
		ft_tiflt(stack_a, avg, stack_b);
	}
}

/*
void	ft_sort_stack(t_stack *stack)
{
	if ()
}
*/


static void	ft_printstack(t_stack stack)
{
	ft_putendl_fd("\nSTACK:", 1);
	while (stack.top > -1)
		ft_putendl_fd(ft_itoa(pop_stack(&stack)), 1);
	ft_putendl_fd("\n", 1);
}

#include <stdio.h>
void	ft_fit_stack_b(t_stack *stack_a, t_stack *stack_b)
{
	int	pos_a;
	int	pos_b;

	pos_a = 0;
	pos_b = 0;
	while (stack_b->top > -1)
	{
		ft_calc_pos(*stack_b, *stack_a, &pos_b, &pos_a);

		
		ft_rotate_stacks(stack_a, pos_a, stack_b, pos_b);
		
		
		
		printf("%d %d\n",pos_a, pos_b);
		ft_printstack(*stack_a);
		ft_printstack(*stack_b);
		push(stack_a, stack_b);
		ft_putendl_fd("pb", 1);
	}
}

void	ft_fit_stack_a(t_stack *stack_a, t_stack *stack_b)
{
	int	pos_a;
	int	pos_b;

	while (stack_b->top > -1)
	{
		ft_calc_pos(*stack_a, *stack_b, &pos_a, &pos_b);

		
		ft_rotate_stacks(stack_a, pos_a, stack_b, pos_b);
		
		
		push(stack_b, stack_a);
		ft_putendl_fd("pa", 1);
	}
}

void abracadabra(t_stack *stack_a, t_stack *stack_b)
{
	
	ft_filter(stack_a, stack_b);
	//ft_fit_stack_b(stack_b, stack_a);
	ft_fit_stack_a(stack_a, stack_b);
	ft_rotpos(stack_a, find_pos(*stack_a, get_min(*stack_a)), "a");
	
	ft_printstack(*stack_a);
	return ;
}