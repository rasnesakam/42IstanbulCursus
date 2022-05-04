/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <rasnesakam@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 15:47:30 by emakas            #+#    #+#             */
/*   Updated: 2022/05/01 15:48:02 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H
# include <mlx.h>
# include <stdlib.h>
# include "../structures.h"

object	*create_player(mlx_vars mlx, int x, int y);

object	*create_enemy(mlx_vars mlx, int x, int y);

object	*create_exit(mlx_vars mlx, int x, int y);

object	*create_collectible(mlx_vars mlx, int x, int y);

object	*create_wall(mlx_vars mlx, int x, int y);

object	*create_floor(mlx_vars mlx, int x, int y);

#endif