/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <rasnesakam@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 10:15:52 by emakas            #+#    #+#             */
/*   Updated: 2022/04/18 15:54:42 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client_bonus.h"

/**
 * SIGUSR1: Data signal
 * SIGUSR2: Clock signal
 */

void	ft_sig(int pid, int signal)
{
	kill (pid, signal);
	usleep (100);
}

void	ft_sendsig(int pid, unsigned char msg, int depth)
{
	int	remain;

	if ((int) msg >= 2 || depth < 8)
		ft_sendsig(pid, (int) msg / 2, depth + 1);
	remain = (int) msg % 2;
	ft_sig (pid, SIGUSR2);
	if (remain == 1)
		ft_sig(pid, SIGUSR1);
}

void	ft_sendmsg(int pid, char *msg)
{
	int	i;

	i = 0;
	while (msg[i] != '\0')
	{
		ft_sendsig (pid, (unsigned char) msg[i], 1);
		i++;
	}
	ft_sendsig (pid, 0, 1);
	ft_sig (pid, SIGUSR2);
}

void	handle(int signal)
{
	if (signal == SIGUSR1)
	{
		ft_putendl_fd ("Message sent", 1);
	}
	exit(0);
}
