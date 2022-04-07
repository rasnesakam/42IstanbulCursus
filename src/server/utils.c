/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <rasnesakam@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 10:02:04 by emakas            #+#    #+#             */
/*   Updated: 2022/04/07 10:12:21 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	handle(int signal)
{
	static int	csize;
	static int	tdata;

	if (signal == SIGUSR1)
		tdata = tdata | 1;
	if (csize == 8)
	{
		if (tdata == 0)
			ft_putendl_fd ("", 1);
		ft_putchar_fd (tdata, 1);
		csize = 0;
		tdata = 0;
	}
	if (signal == SIGUSR2)
	{
		tdata = tdata << 1;
		csize++;
	}
}
