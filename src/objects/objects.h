/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <rasnesakam@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 15:47:30 by emakas            #+#    #+#             */
/*   Updated: 2022/06/27 19:47:54 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H
# include <mlx.h>
# include <stdlib.h>
# include "../structures.h"
# include <stdio.h>



t_object	create_player(t_mlx mlx, int x, int y);

t_object	create_enemy(int x, int y);

t_object	create_exit(int x, int y);

t_object	create_collectible(int x, int y);

t_object	create_wall(int x, int y);

t_object	create_floor(int x, int y);

t_object	create_object(int x, int y, int orientation, char *img[2], char code);

#endif