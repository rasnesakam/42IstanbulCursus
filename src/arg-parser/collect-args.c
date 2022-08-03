/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect-args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <rasnesakam@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 17:21:41 by emakas            #+#    #+#             */
/*   Updated: 2022/08/03 19:34:03 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arg-parser.h"
#include "../../libft/libft.h"

char	**collect_args(int ac, char **av)
{
	char	**args;
	char	**sargs;
	int		size;
	int		pindex;
	int		sindex;

	size = count_args(ac, av);
	pindex = 0;
	aindex = 0;
	args = malloc(size * sizeof(char));
	while (aindex < ac)
	{
		sindex = 0;
		sargs = ft_split(av[aindex], ' ');
		while (sindex < count_words(av[aindex]))
		{
			args[aindex] = sargs[sindex];
			aindex++;
			sindex++;
		}
		aindex++;
	}
}
