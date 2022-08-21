/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 10:07:30 by emakas            #+#    #+#             */
/*   Updated: 2022/08/21 11:20:27 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "checker.h"

int	main(int ac, char **av)
{
	char	**args;
	int		count;
	int		*list;
	t_stack	*stack_a;
	t_stack	*stack_b;

	check_args(av, ac);
	args = collect_args(ac, av);
	count = count_args(ac, av);
	stack_a = create_stack(count);
	stack_b = create_stack(count);
	if (verify_args(count, args) && stack_a && stack_b)
	{
		list = convert_args(count, args);
		load_stack(stack_a, list, count);
		start_checker(stack_a, stack_b);
		if (check_sorted(stack_a))
			ft_putendl_fd("OK", 1);
		else
			ft_putendl_fd("KO", 1);
		destroy_stack(stack_a);
		destroy_stack(stack_b);
	}
	else if (count > 0)
		ft_putendl_fd("Error", 2);
	return (0);
}