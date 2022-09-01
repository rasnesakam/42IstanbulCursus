/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify-args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 15:58:00 by emakas            #+#    #+#             */
/*   Updated: 2022/09/01 16:57:37 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arg_verifier.h"

int	verify_arg(char *arg)
{
	int	index;

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
	int	i;

	i = 0;
	if (ac == 0)
		return (0);
	while (i < ac)
	{
		if (!verify_arg(args[i]))
			return (0);
		i++;
	}
	return (1);
}
