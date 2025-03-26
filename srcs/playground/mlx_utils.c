/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salabbe <salabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 19:33:16 by salabbe           #+#    #+#             */
/*   Updated: 2025/03/26 16:49:55 by salabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void window_hook(int event, void *param)
{
	t_map *map;
	
	map = (t_map*)param;
	if (event == 0)
		mlx_loop_end(map->mlx);
}

void key_handler(int event, void *param)
{
	t_map *map;
	
	map = (t_map*)param;
	if (event == 41)
		mlx_loop_end(map->mlx);
	if (event == 26)
		update_player(map, event);
	if (event == 22)
		update_player(map, event);
	if (event == 7)
		update_player(map, event);
	if (event == 4)
		update_player(map, event);
}

void free_engine(t_map *map)
{
	mlx_destroy_window(map->mlx, map->win);
	mlx_destroy_image(map->mlx, map->floor);
	mlx_destroy_context(map->mlx);
}

void	take_collectible(t_map *map, int x, int y)
{
	if (map->grid[x][y] == 'C')
	{
		map->collected++;
		map->grid[x][y] = '0';
	}
}

void update_player(t_map *map, int event)
{
	int p_x = map->player.coords.x;
	int p_y = map->player.coords.y;
	
	if (event == 26)
		p_y -= 1;
	if (event == 22)
		p_y += 1;
	if (event == 7)
		p_x += 1;
	if (event == 4)
		p_x -= 1;
	if (map->grid[p_y][p_x] != '1') 
	{
		map->player.coords.x = p_x;
		map->player.coords.y = p_y;
	}
	if (map->grid[p_y][p_x] == 'C')
		take_collectible(map, p_y, p_x);
	if (map->grid[p_y][p_x] == 'E' && map->exit.winnable == 1)
		mlx_loop_end(map->mlx);

}


