/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <rasnesakam@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 17:21:34 by emakas            #+#    #+#             */
/*   Updated: 2022/07/31 19:44:11 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_exit(char *message, t_mlx *mlx, int err)
{
	errno = err;
	ft_putendl_fd ("ERROR", 2);
	perror (message);
	safe_exit (1, mlx);
}

void	set_message(t_mlx *mlx, char *message)
{
	if (mlx->message != NULL)
	{
		ft_bzero(mlx->message, ft_strlen(mlx->message));
		free(mlx->message);
	}
	mlx->message = message;
}


