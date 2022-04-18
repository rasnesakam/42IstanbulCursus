/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <rasnesakam@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 10:03:30 by emakas            #+#    #+#             */
/*   Updated: 2022/04/18 15:54:57 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server_bonus.h"

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
