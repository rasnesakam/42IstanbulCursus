#ifndef CHARACTERS_H
# define CHARACTERS_H
# include "structures.h"

player	*get_player(void *mlx);
void	put_player_mlx(void *mlx, void *mlx_win, player *pl);

#endif