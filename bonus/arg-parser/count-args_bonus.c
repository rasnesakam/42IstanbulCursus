/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count-args_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 16:46:12 by emakas            #+#    #+#             */
/*   Updated: 2022/08/21 18:44:20 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arg_parser_bonus.h"

int	count_words(char *c)
{
	unsigned int	count;
	unsigned int	i;
	static char		delimiter = ' ';

	count = 0;
	i = 0;
	while (c && c[i] != '\0')
	{
		if (c[i] == delimiter)
			i++;
		else
		{
			count++;
			while (c[i] && c[i] != delimiter)
				i++;
		}
	}
	return (count);
}

int	count_args(int ac, char **av)
{
	int	count;
	int	index;

	index = 1;
	count = 0;
	while (index < ac)
	{
		count += count_words(av[index]);
		index++;
	}
	return (count);
}
