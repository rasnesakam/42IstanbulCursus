/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect-args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 17:21:41 by emakas            #+#    #+#             */
/*   Updated: 2022/09/01 16:37:49 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arg_parser.h"

char	**collect_args(int ac, char **av)
{
	char	**args;
	char	**sargs;
	int		li;
	int		ai;
	int		si;

	li = 1;
	ai = 0;
	args = (char **) malloc(sizeof(char *) * count_args(ac, av));
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
