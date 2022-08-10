#include "../stack/stack.h"
#include "../verbs/verbs.h"

void ft_rotpos(t_stack *stack, int pos)
{
	if (pos > (stack->top / 2))
	{
		pos = stack->top - pos;
		while (pos--)
		{
			revr(stack);

		}
	}
	else
	{}
}