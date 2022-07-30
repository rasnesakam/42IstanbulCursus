/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <rasnesakam@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 17:21:34 by emakas            #+#    #+#             */
/*   Updated: 2022/07/30 17:21:44 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_exit(char *message, int err)
{
	errno = err;
	ft_putendl_fd ("ERROR", 2);
	perror (message);
	exit (1);
}
