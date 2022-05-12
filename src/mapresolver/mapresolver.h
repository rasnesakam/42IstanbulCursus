/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapresolver.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 15:44:22 by emakas            #+#    #+#             */
/*   Updated: 2022/05/12 18:55:45 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPRESOLVER_H
# define MAPRESOLVERS_H
# include "../structures.h"
# include "../ext/get_next_line.h"
# include <fcntl.h>
# include <errno.h>
# include <stdio.h>

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
 * Vadidates the map file with given path
 * @param maddr: Map file address
 * @param xsize: Horizontal size for map. Will be set after validation
 * @param ysize: Vertical size for map. Will be set after validation
 */
int		validate_map(char *maddr, int *xsize, int *ysize);

/**
 * renderline(mlx_vars,int,char*)
 * 
 * renders char* and puts mlx_vars an object corresponding to char in char*
 * mlx: structure that contains mlx library vars such as mlx and mlx_win
 * lnum: line number for defining y axis for the location of object 
 */
void	renderline(t_mlx mlx, int lnum, char *line);

/**
 * @brief Render chars in line for map
 * 
 * @param mlx Minilibx var for interacting with window
 * @param lnum Line number
 * @param cnum Column number
 * @param code Char code for objects in map
 */
void	renderpoint(t_mlx mlx, int lnum, int cnum, char code);

#endif