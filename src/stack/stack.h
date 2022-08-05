
#ifndef STACK_H
# define STACK_H
# include <stdlib.h>

typedef struct	s_stack
{
	int			*datas;
	int			top;
	int			size;
} 				t_stack;

t_stack	*create_stack(int size);
void	destroy_stack(t_stack *stack);
void	push_stack(t_stack *stack, int value);
int		pop_stack(t_stack *stack);

#endif