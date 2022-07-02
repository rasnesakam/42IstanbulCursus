
#ifndef STACK_H
# define STACK_H

typedef struct	s_stack
{
	int			*stack;
	int			top;
	int			size;
} 				t_stack;

t_stack	create_stack(int size);

void	push_stack(t_stack *stack, int val);
int		pop_stack(t_stack *stack);

#endif