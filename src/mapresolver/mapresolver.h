/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapresolver.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 15:44:22 by emakas            #+#    #+#             */
/*   Updated: 2022/05/17 13:58:49 by emakas           ###   ########.fr       */
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
 * resolve_map(mlx_vars,char *);
 * 
 * @param main function for rendering string maps into window
 * @param mlx: structure that stores mlx library variables
 * @param maddr: map file address
 */
void	resolve_map(t_mlx mlx, char *maddr);

/**
 * validate_map(char*)
 * 
 * @brief Vadidates the map file with given path
 *
 * @param maddr: Map file address
 * @param xsize: Horizontal size for map. Will be set after validation
 * @param ysize: Vertical size for map. Will be set after validation
 */
int		validate_map(char *maddr, int *xsize, int *ysize);

/**
 * @brief Render line for mapping
 *
 * @param mlx Minilibx var for interacting with window
 * @param lindex Line index
 * @param line The line will be rendering
 */
void	renderline(t_mlx mlx, int lindex, char *line);

/**
 * @brief Render chars in line for map
 * 
 * @param mlx Minilibx var for interacting with window
 * @param lindex Line index
 * @param cindex Column index
 * @param code Char code for objects in map
 */
void	renderpoint(t_mlx mlx, int lindex, int cindex, char code);

#endif