/*
 * Filename: /nfs/homes/ygaiffie/Documents/solong_salabbe/srcs/playground/mlx_engine.c
 * Path: /nfs/homes/ygaiffie/Documents/solong_salabbe/srcs/playground
 * Created Date: Thursday, January 1st 1970, 1:00:00 am
 * Author: Yohann Gaiffier
 * 
 * Copyright (c) 2025 Your Company
 */

#include "../../include/so_long.h"
#include "../../include/mlx_engine.h"

void window_hook(int event, void* param)
{
	t_map *map;
	
	map = (t_map*)param;
    if(event == 0)
        mlx_loop_end(map->mlx);
}

static void put_grid(t_map *map)
{
	t_vec2i coord;

	coord = (t_vec2i){0 , 0};
	while (coord.y < map->column_height)
	{
		coord.x = 0;
		while (map->grid[coord.y][coord.x])
		{
			mlx_put_image_to_window(map->mlx, map->win, map->floor, coord.x << 5, coord.y << 5);
			if (map->grid[coord.y][coord.x] == '1')
				mlx_put_image_to_window(map->mlx, map->win, map->wall, coord.x << 5, coord.y << 5);
			coord.x++;
		}
		coord.y++;
	}	
}

void	render_loop(void* param)
{
	t_map *map;
	
	map = (t_map*)param;
	mlx_clear_window(map->mlx, map->win, (mlx_color){ .rgba = 0x00000000 });
	// mlx_string_put(map->mlx, map->win, 20, 20, (mlx_color){ .rgba = 0x0000FFFF }, "Coucou");
	put_grid(map);
	// mlx_put_image_to_window(map->mlx, map->win, map->floor, 0, 0);
	// mlx_put_image_to_window(map->mlx, map->win, map->wall, 0, 0);
}

void free_engine(t_map *map)
{
	mlx_destroy_window(map->mlx, map->win);
	mlx_destroy_image(map->mlx, map->floor);
	mlx_destroy_context(map->mlx);
}