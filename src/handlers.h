/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <rasnesakam@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 14:12:09 by emakas            #+#    #+#             */
/*   Updated: 2022/07/30 14:12:16 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HANDLERS_H
# define HANDLERS_H
# include "structures.h"

void	handle_exit(int keycode, t_mlx *vars);
void	handle_player(int keycode, t_mlx *vars);

#endif