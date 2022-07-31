/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <rasnesakam@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 14:06:18 by emakas            #+#    #+#             */
/*   Updated: 2022/07/31 19:29:28 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handlers.h"
#include "utils/utils.h"

void	handle_exit(int keycode, t_mlx *vars)
{
	if (keycode == 53)
	{
		mlx_destroy_window (vars->mlx, vars->win);
		ft_putendl_fd ("Program terminated", 1);
		safe_exit (0, vars);
	}
}

/**
 * W => 13
 * A => 0
 * S => 1
 * D => 2
 */
void	handle_player(int keycode, t_mlx *vars)
{
	if (keycode == 13)
		vars->player = move_object(
				vars, vars->player, vars->player->x, vars->player->y - 1);
	else if (keycode == 0)
	{
		vars->player = move_object(
				vars, vars->player, vars->player->x - 1, vars->player->y);
		vars->player->orientation = 0;
	}
	else if (keycode == 1)
		vars->player = move_object(
				vars, vars->player, vars->player->x, vars->player->y + 1);
	else if (keycode == 2)
	{
		vars->player = move_object(
				vars, vars->player, vars->player->x + 1, vars->player->y);
		vars->player->orientation = 1;
	}
}
