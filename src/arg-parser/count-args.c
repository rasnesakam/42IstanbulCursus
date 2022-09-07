/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count-args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <rasnesakam@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 16:46:12 by emakas            #+#    #+#             */
/*   Updated: 2022/09/07 15:48:05 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arg_parser.h"

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
