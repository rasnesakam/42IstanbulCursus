/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <rasnesakam@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 10:12:58 by emakas            #+#    #+#             */
/*   Updated: 2022/04/18 15:54:25 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client_bonus.h"

int	main(int argc, char **argv)
{
	int		pid;
	char	*message;

	if (argc >= 3)
	{
		pid = ft_atoi (argv[1]);
		message = argv[2];
		signal (SIGUSR1, handle);
		ft_sendmsg (pid, message);
		ft_sendmsg (pid, ft_itoa(getpid()));
		while (1)
			pause();
	}
	return (0);
}
