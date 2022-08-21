/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 04:39:43 by emakas            #+#    #+#             */
/*   Updated: 2022/08/21 13:33:53 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./arg-parser/arg_parser.h"
#include "./arg-verifier/arg_verifier.h"
#include "./arg-converter/arg_converter.h"
#include "./magic-alg/magic_alg.h"
#include "./stack/stack.h"

static void	load_stack(t_stack *stack, int *list, int size)
{
	while (--size >= 0)
	{
		push_stack(stack, list[size]);
	}
}

static void	sort_simple(int **sortedlist, int size)
{
	int	index;
	int	sub_index;
	int	minimum;
	int	min_index;

	index = 0;
	while (index < size)
	{
		sub_index = index;
		min_index = sub_index;
		while (sub_index < size)
		{
			if ((*sortedlist)[sub_index] < (*sortedlist)[min_index])
				min_index = sub_index;
			sub_index++;
		}
		if ((*sortedlist)[min_index] < (*sortedlist)[index])
		{
			minimum = (*sortedlist)[min_index];
			(*sortedlist)[min_index] = (*sortedlist)[index];
			(*sortedlist)[index] = minimum;
		}
		index++;
	}
}

static int	find_index(int *list, int search, int size)
{
	int	index;

	index = 0;
	while (index < size)
	{
		if (list[index] == search)
			return (index);
		index++;
	}
	return (index);
}

static void	simplify(int **list, int size)
{
	int	*sorted;
	int	index;

	sorted = malloc(sizeof(int) * size);
	if (!sorted)
		ft_error("COULDN'T ALLOCATED DATA");
	index = 0;
	while (index < size)
	{
		sorted[index] = (*list)[index];
		index++;
	}
	sort_simple(&sorted, size);
	index = 0;
	while (index < size)
	{
		(*list)[index] = find_index(sorted, (*list)[index], size);
		index++;
	}
}

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
		simplify(&list, count);
		load_stack(stack_a, list, count);
		if (check_sorted(*stack_a) == 0)
			abracadabra(stack_a, stack_b);
		destroy_stack(stack_a);
		destroy_stack(stack_b);
	}
	else if (count > 0)
		ft_putendl_fd("Error", 2);
	return (0);
}
