/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 09:54:50 by emakas            #+#    #+#             */
/*   Updated: 2022/08/21 09:59:01 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arg_verifier.h"

int	check_arg(char *str)
{
	while (*str)
	{
		if (ft_isdigit(*str++))
			return (1);
	}
	return (0);
}

void	check_args(char **av, int ac )
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (check_arg(av[i]) == 0)
			ft_error(NULL);
		i++;
	}
}
