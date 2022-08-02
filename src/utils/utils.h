/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <rasnesakam@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 14:11:53 by emakas            #+#    #+#             */
/*   Updated: 2022/08/02 03:37:14 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include <mlx.h>
# include "../structures.h"
# include "../objects/objects.h"
# include <libft.h>
# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>

void		put_object(t_mlx *mlx, t_object *object, int x, int y);
void		ft_exit(char *message, t_mlx *mlx, int err);
int			render(void *vars);
void		set_message(t_mlx *mlx, char *message);
t_object	get_object(char code, int x, int y);
t_object	*move_object(t_mlx *mlx, t_object *obj, int x, int y);
int			find_ocs(t_mlx *mlx, char otype);
t_object	*find_object(t_mlx *mlx, char otype);
int			list_size(t_object **list);
void		list_remove(t_object ***reflist, t_object *ref);
t_object	*move_in_map(t_mlx *mlx, t_object *target, t_object *source);
void		safe_exit(int code, t_mlx *mlx);
#endif