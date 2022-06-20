/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <rasnesakam@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 15:47:30 by emakas            #+#    #+#             */
/*   Updated: 2022/06/20 17:00:46 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H
# include <mlx.h>
# include <stdlib.h>
# include "../structures.h"
# include <stdio.h>



t_object	*create_player(t_mlx mlx, int x, int y);

t_object	*create_enemy(t_mlx mlx, int x, int y);

t_object	*create_exit(t_mlx mlx, int x, int y);

t_object	*create_collectible(t_mlx mlx, int x, int y);

t_object	*create_wall(t_mlx mlx, int x, int y);

t_object	*create_floor(t_mlx mlx, int x, int y);

t_object	*create_object(t_mlx mlx, int x, int y, int orientation, char *img[2], char code);

#endif