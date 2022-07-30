/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_all_wall.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <rasnesakam@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 07:15:02 by emakas            #+#    #+#             */
/*   Updated: 2022/07/30 13:43:37 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mapresolver.h"

void	check_all_wall(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != '1')
			ft_exit ("MAP SHOULD BE SURROUNDED BY WALLS", EINVAL);
		i++;
	}
}
