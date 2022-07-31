#include "utils.h"

void	destroy_model(t_mlx *mlx)
{
	int			i;
	int			j;
	int			k;
	//t_object	*obj;

	i = 0;
	while (i < *mlx->mheight)
	{
		j = 0;
		while (j < *mlx->mwidth)
		{
			k = 0;
			/*
			while (k < 2)
			{
				obj = &(*mlx->mmodel)[i][j][k];
				destroy_object(obj);
				free(obj);
				k++;
			}
			*/
			free((*mlx->mmodel)[i][j]);
			j++;
		}
		free((*mlx->mmodel)[i]);
		i++;
	}
	free(mlx->mmodel);
}

void	destroy_list(t_mlx *mlx)
{
	int i;

	i = 0;
	while (list_size(*mlx->collectibles) > 0)
	{
		list_remove(mlx->collectibles,(*mlx->collectibles)[i]);
	}
	free(mlx->collectibles);
}

void destroy_mlx(t_mlx *mlx)
{
	(void)mlx;
	//destroy_model(mlx);
	//destroy_list(mlx);
	//free(mlx->message);
	//mlx_destroy_window(mlx->mlx, mlx->win);
}

void safe_exit(int code, t_mlx *mlx)
{
	if (mlx != NULL)
	{
		destroy_mlx(mlx);
	}
	system("leaks so_long");
	exit(code);
}