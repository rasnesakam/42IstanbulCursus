/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <rasnesakam@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 10:02:04 by emakas            #+#    #+#             */
/*   Updated: 2022/04/09 17:01:06 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	handlesig(int tdata)
{
	static int	pid;
	int num;

	num = tdata - 48;
	if (num >= 0)
		pid = (pid * 10) + num;
	if (tdata == 0)
		kill (pid, SIGUSR1);
}

void	ft_print(int tdata, int fin)
{
	if (fin == 1)
		handlesig(tdata);
	else
	{
		ft_putchar_fd(tdata,1);
		if (tdata == 0)
			ft_putendl_fd("",1);
	}
}

int	ft_toggle(int fin)
{
	if (fin == 1)
		return (0);
	else
		return (1);
}

void	handle(int signal)
{
	static int	csize;
	static int	tdata;
	static int 	fin;

	if (signal == SIGUSR1)
		tdata = tdata | 1;
	if (signal == SIGUSR2)
	{
		csize++;
		if (csize < 9)
			tdata = tdata << 1;
		else
		{
			csize = 1;
			if (tdata == 0)
			{
				csize = 0;
				fin = ft_toggle(fin);
			}
			ft_print(tdata,fin);
			tdata = 0;
		}
	}
}
