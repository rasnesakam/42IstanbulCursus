/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 15:47:30 by emakas            #+#    #+#             */
/*   Updated: 2022/05/12 18:29:57 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H
# include <mlx.h>
# include <stdlib.h>
# include "../structures.h"

typedef struct s_object
{
	void	*img;
	char	*image_addr[2];
	int		width;
	int		height;
	int		x;
	int		y;
	int		orientation;
    void    (*collision)(t_object,t_object);
}
t_object;


t_object	*create_player(t_mlx mlx, int x, int y);

t_object	*create_enemy(t_mlx mlx, int x, int y);

t_object	*create_exit(t_mlx mlx, int x, int y);

t_object	*create_collectible(t_mlx mlx, int x, int y);

t_object	*create_wall(t_mlx mlx, int x, int y);

t_object	*create_floor(t_mlx mlx, int x, int y);

t_object	*create_object(t_mlx mlx, int x, int y, int orientation, char *img[2]);

#endif