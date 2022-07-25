#include "utils.h"

void	put_object(t_mlx *vars, t_object *object, int x, int y)
{
	void	*img;
	
	if (object->otype != '\0')
	{
		img = mlx_xpm_file_to_image(vars->mlx,object->image_addr[object->orientation],&object->width,&object->height);
		
		mlx_put_image_to_window (vars->mlx, vars->win, img, x * vars->object_size, y * vars->object_size);
		mlx_destroy_image(vars->mlx,img);
	}
}

void	ft_exit(char *message, int err)
{
	errno = err;
	ft_putendl_fd("ERROR",2);
	perror(message);
	exit(1);
}

void	render_message(t_mlx *vars)
{
	static char *msg;
	static int	index;
	static int	time;
	int			timeunit;

	timeunit = 2;
	if (msg == NULL)
		msg = "";
	if (ft_strncmp(vars->message,msg,index) != 0)
	{
		printf("message: %s\noriginal: %s\n",msg,vars->message);
		msg = "";
		index = 0;
	}
	if (index <= (int) ft_strlen(vars->message))
	{
		if (time % timeunit == 0)
			index++;
		msg = ft_substr(vars->message,0,index);	
	}
	time = (time + 1) % timeunit;
	mlx_string_put(vars->mlx,vars->win,10,10,0x00FFFFFF,msg);
}

void	render_objects(t_mlx *vars)
{
	t_object	*obj;
	int			row;
	int			col;
	int			layer;

	row = 0;
	while (row < *vars->mheight)
	{
		col = 0;
		while (col < *vars->mwidth)
		{
			layer = 0;
			while (layer < 2)
			{
				obj = &((*vars->mmodel)[row][col][layer]);
				if (obj->otype != '\0')
					put_object(vars,obj,col,row);
				layer++;
			}
			col++;
		}
		row++;
	}
}

int	render(void *tvars)
{
	t_mlx		*vars;

	vars = (t_mlx *) tvars;
	mlx_clear_window(vars->mlx,vars->win);
	render_objects(vars);
	render_message(vars);
	
	return 0;
}

t_object	get_object(char code, int x, int y)
{
	if (code == '0')
		return (create_floor(x, y));
	if (code == '1')
		return (create_wall(x, y));
	if (code == 'C')
		return (create_collectible(x, y));
	if (code == 'E')
		return (create_exit(x, y));
	if (code == 'P')
		return (create_player(x, y));
	else
		ft_exit("INVALID RULE FOR MAPPING",EINVAL);
	return (create_floor(x, y));
}

/**
 * @brief Moves Objects to spesific x and y coordinates
 * TODO: apply changes to map model
 * Bir yerler gereksiz gibi sanki ama nereler
 */
t_object	*move_object(t_mlx *vars, t_object *obj, int x, int y)
{
	t_object	***map;
	t_object	*target;

	map = *vars->mmodel;
	if ((x > 0 || x < *vars->mwidth) 
			&& (y > 0 || y < *vars->mheight))
	{
		printf("MOVING OBJ FROM: (%d,%d) TO: (%d,%d)\n",obj->x,obj->y,x,y);
		
		target = &map[y][x][1];
		if (target->on_collision != NULL)
			return (target->on_collision(vars,target,obj));
		else
		{
			*target = *obj;
			target->x = x;
			target->y = y;
			destroy_object(obj);
			return (target);
		}

	}
	return (obj);
}

/**
 * @brief Find spesific objects in array
 * 
 */

int 	list_size(t_object **list)
{
	int count = 0;
	while (list && list[count])
		count++;
	return count;
}

void	list_push(t_object ***list, t_object *obj)
{
	t_object ** newlist;
	int	index = 0;
	newlist = (t_object **) ft_calloc(sizeof(t_object *),list_size(*list) + 2);
	if (newlist == NULL)
		return ;
	if (list == NULL)
		return ;
	while (*list && (*list)[index])
	{
		newlist[index] = (*list)[index];
		index++;
	}
	newlist[index] = obj;
	free(*list);
	*list = newlist;
}

void	list_remove(t_object ***reflist, t_object *ref)
{
	t_object	**nlist;
	int index;
	int nindex;
	printf("creating array with size: %d",list_size(*reflist));
	nlist = (t_object **)ft_calloc(sizeof(t_object *),list_size(*reflist));
	if (!nlist)
		return ;
	index = 0;
	nindex = 0;
	while ((*reflist)[index] != NULL)
	{
		if ((*reflist)[index] != ref)
		{
			nlist[nindex] = (*reflist)[index];
			nindex++;
			printf("nindex: %d\n",nindex);
		}
		index++;
	}
	free(*reflist);
	*reflist = nlist;
}

t_object	**find_objects(t_mlx mlx, char otype)
{
	t_object	***map;
	t_object	**list;
	t_object	obj;
	int			row;
	int			col;

	map = *mlx.mmodel;
	row = 0;
	list = (t_object **) ft_calloc(sizeof(t_object *),1);
	while (row < *mlx.mheight)
	{
		col = 0;
		while (col < *mlx.mwidth)
		{
			obj = map[row][col][1];
			if (obj.otype == otype)
				list_push(&list,&map[row][col][1]);
			col++;
		}
		row++;
	}
	return (list);
}