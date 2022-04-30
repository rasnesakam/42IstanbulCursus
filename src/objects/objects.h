#ifndef PLAYER_H
# define PLAYER_H
# include <mlx.h>
# include <stdlib.h>
# include "../structures.h"

object	*create_player(mlx_vars mlx, int x, int y);

object	*create_enemy(mlx_vars mlx, int x, int y);

object	*create_exit(mlx_vars mlx, int x, int y);

object	*create_collectible(mlx_vars mlx, int x, int y);

object	*create_wall(mlx_vars mlx, int x, int y);

object	*create_floor(mlx_vars mlx, int x, int y);

#endif