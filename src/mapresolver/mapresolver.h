/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapresolver.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <rasnesakam@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 15:44:22 by emakas            #+#    #+#             */
/*   Updated: 2022/05/04 16:09:46 by emakas           ###   ########.fr       */
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
 * main function for rendering string maps into window
 * mlx: structure that stores mlx library variables
 * maddr: map file address
 */
void	resolve_map(mlx_vars mlx, char *maddr);

/**
 * validate_map(char*)
 * 
 * Vadidates the map file with given path
 * maddr: Map file address
 * xsize: Horizontal size for map. Will be set after validation
 * ysize: Vertical size for map. Will be set after validation
 */
int		validate_map(char *maddr, int *xsize, int *ysize);

/**
 * renderline(mlx_vars,int,char*)
 * 
 * renders char* and puts mlx_vars an object corresponding to char in char*
 * mlx: structure that contains mlx library vars such as mlx and mlx_win
 * lnum: line number for defining y axis for the location of object 
 */
void	renderline(mlx_vars mlx, int lnum, char *line);

#endif