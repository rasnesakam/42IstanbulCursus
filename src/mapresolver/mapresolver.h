/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapresolver.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <rasnesakam@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 15:44:22 by emakas            #+#    #+#             */
/*   Updated: 2022/07/30 20:24:24 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPRESOLVER_H
# define MAPRESOLVER_H
# include "../structures.h"
# include "../utils/utils.h"
# include "../objects/objects.h"
# include "../ext/get_next_line.h"
# include <fcntl.h>
# include <libft.h>

t_object	***create_map_model(t_mlx mlx, char *file);

int			validate_map(char *maddr, int *xsize, int *ysize);

int			openorext(char *maddr);

char		*read_line(int fd);

void		check_all_wall(char *line);

t_object	*renderpoint(int lindex, int cindex, char code);

t_object	**renderline(int lindex, int size, char *line);

#endif