/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <rasnesakam@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 06:43:59 by emakas            #+#    #+#             */
/*   Updated: 2022/07/30 14:07:29 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct s_object	t_object;
typedef struct s_mlx	t_mlx;

struct s_object
{
	char		otype;
	char		**image_addr;
	int			width;
	int			height;
	int			x;
	int			y;
	int			orientation;
	t_object	*(*on_collision)(t_mlx *mlx,
			struct s_object *self, struct s_object *smasher);
};

struct s_mlx
{
	void		*mlx;
	void		*win;
	t_object	****mmodel;
	t_object	***collectibles;
	t_object	*player;
	int			*movecount;
	int			*mwidth;
	int			*mheight;
	int			object_size;
	char		*message;
};

#endif