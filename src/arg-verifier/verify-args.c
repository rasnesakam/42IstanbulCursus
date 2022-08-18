/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify-args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 15:58:00 by emakas            #+#    #+#             */
/*   Updated: 2022/08/18 02:03:24 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arg-verifier.h"
#include <stdio.h>

static int	ft_max(int integer1, int integer2)
{
	if (integer1 >= integer2)
		return (integer1);
	else
		return (integer2);
}

static int	ft_cmp_bound_ints(char *act_string)
{
	int		conv_int;

	conv_int = ft_atoi(act_string);
	if ((conv_int == -1 || conv_int == 0) && ft_strlen(act_string) > 2)
		return (1);
	return (0);
}

static int	ft_look_between(char **list, char *look, int after, int end)
{
	int	index;

	index = after;
	while (index <= end)
	{
		if (ft_strncmp(list[index],
				look, ft_max(ft_strlen(list[index]), ft_strlen(look))) == 0)
			return (1);
			index++;
	}
	return (0);
}

int	verify_arg(char *arg)
{
	int	index;
	if (ft_cmp_bound_ints(arg))
		return (0);
	index = 0;
	if (arg[0] == '-' || arg[0] == '+')
		index++;
	if (index >= (int) ft_strlen(arg))
		return (0);
	while (index < (int) ft_strlen(arg) && arg[index] != '\0')
	{
		if (ft_isdigit((int) arg[index]) == 0)
			return (0);
		index++;
	}
	return (1);
}

int	verify_args(int ac, char **args)
{
	int		i;
	int		si;

	i = 0;
	if (ac == 0)
		return (0);
	while (i < ac)
	{
		if (verify_arg(args[i]))
		{
			si = i + 1;
			if (ft_look_between(args, args[i], si, ac - 1))
				return (0);
		}
		else
			return (0);
		i++;
	}
	return (1);
}
