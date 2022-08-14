
#ifndef MAGICALG_H
# define MAGICALG_H
# include "../stack/stack.h"

void	abracadabra(t_stack *stack_a, t_stack *stack_b);
void	ft_calc_pos(t_stack stack_a, t_stack stack_b, int *pos_a, int *pos_b);
void	ft_rotate_stacks(t_stack *stack_a, int pos_a, t_stack *stack_b, int pos_b);
int		check_sorted(t_stack *stack);
int	    find_pos(t_stack stack, int number);
void    ft_rotpos(t_stack *stack, int pos, char *stack_name);

#endif