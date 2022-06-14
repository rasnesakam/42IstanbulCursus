/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapresolver.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <rasnesakam@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 15:44:22 by emakas            #+#    #+#             */
/*   Updated: 2022/06/14 18:45:50 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPRESOLVER_H
# define MAPRESOLVER_H
# include "../structures.h"
# include "../utils.h"
# include "../objects/objects.h"
# include "../ext/get_next_line.h"
# include <fcntl.h>

/**
 * @brief Create a map model object
 * 
 * @param file 
 * @return t_object*** An array of the objects with 3 dimension (x,y,z=2)
 */
t_object ***create_map_model(t_mlx mlx, char *file);

/**
 * @brief Valiate map if available for system
 */
int	validate_map(char *maddr, int *xsize, int *ysize);


#endif