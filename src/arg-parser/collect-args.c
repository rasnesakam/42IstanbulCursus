/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect-args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <rasnesakam@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 17:21:41 by emakas            #+#    #+#             */
/*   Updated: 2022/08/04 15:58:47 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arg-parser.h"

char	**collect_args(int ac, char **av)
{
	char	**args;
	char	**sargs;
	int		li;
	int		ai;
	int		si;

	li = 1;
	ai = 0;
	args = malloc(sizeof(char *) * count_args(ac, av));
	while (li < ac)
	{
		si = 0;
		sargs = ft_split(av[li], ' ');
		while (si < count_words(av[li]))
		{
			args[ai] = ft_strtrim(sargs[si], "\t\n\v\f\r");
			free(sargs[si]);
			ai++;
			si++;
		}
		free(sargs);
		li++;
	}
	return (args);
}
