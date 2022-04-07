/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <rasnesakam@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 10:03:30 by emakas            #+#    #+#             */
/*   Updated: 2022/04/07 10:11:11 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_putendl_fd (ft_itoa (pid), 1);
	signal (SIGUSR1, handle);
	signal (SIGUSR2, handle);
	while (1)
		pause();
	return (0);
}
