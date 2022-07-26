/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <rasnesakam@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 15:47:30 by emakas            #+#    #+#             */
/*   Updated: 2022/07/26 07:46:22 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H
# include <mlx.h>
# include <stdlib.h>
# include "../structures.h"
# include "../utils.h"
# include <stdio.h>

t_object	create_player(int x, int y);

t_object	create_exit(int x, int y);

t_object	create_collectible(int x, int y);

t_object	create_wall(int x, int y);

t_object	create_floor(int x, int y);

t_object	create_object(int x, int y, int orientation, char *img[2], char code);

t_object	create_null();

void		destroy_object(t_object *obj);

#endif