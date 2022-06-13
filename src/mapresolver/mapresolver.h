/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapresolver.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 15:44:22 by emakas            #+#    #+#             */
/*   Updated: 2022/06/11 22:26:39 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPRESOLVER_H
# define MAPRESOLVERS_H
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
t_object ***create_map_model(char *file);

t_object ***move_object(t_object ***map, int x, int y);

#endif