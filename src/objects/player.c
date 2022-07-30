/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <rasnesakam@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 13:49:54 by emakas            #+#    #+#             */
/*   Updated: 2022/07/30 13:50:11 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"

t_object	create_player(int x, int y)
{
	t_object		player;
	char			**images;

	images = malloc(sizeof(char *) * 2);
	images[0] = "./res/characters/player/amogus_left.xpm";
	images[1] = "./res/characters/player/amogus_right.xpm";
	player = create_object(
			x,
			y,
			images,
			'P'
			);
	return (player);
}
