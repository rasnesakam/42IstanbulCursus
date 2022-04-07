/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <rasnesakam@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 10:12:58 by emakas            #+#    #+#             */
/*   Updated: 2022/04/07 10:15:01 by emakas           ###   ########.fr       */
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
	}
	return (0);
}
