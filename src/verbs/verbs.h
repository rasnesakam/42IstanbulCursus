
#ifndef VERBS_H
# define VERBS_H
# include "../stack/stack.h"

void	swap(t_stack *t_stack);

void	sswap(t_stack *stack_a, t_stack *stack_b);

void	push(t_stack *stack_from, t_stack *stack_to);

void	rotate(t_stack *t_stack);

void	rrotate(t_stack *stack_a, t_stack *stack_b);

void	revr(t_stack *t_stack);

void	revrr(t_stack *stack_a, t_stack *stack_b);

#endif