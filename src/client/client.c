/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <rasnesakam@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 10:12:58 by emakas            #+#    #+#             */
/*   Updated: 2022/04/09 17:16:20 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int	main(int argc, char **argv)
{
	int		pid;
	char	*message;

	if (argc >= 3)
	{
		pid = ft_atoi (argv[1]);
		message = argv[2];
		ft_sendmsg (pid, message);
		ft_sendmsg (pid, ft_itoa(getpid()));
	}
	signal (SIGUSR1, handle);
	while (1)
		pause();
	return (0);
}
