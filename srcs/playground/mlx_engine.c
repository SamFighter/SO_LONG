/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_engine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salabbe <salabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 19:28:54 by salabbe           #+#    #+#             */
/*   Updated: 2025/04/02 15:28:38 by salabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"
#include "../../include/mlx_engine.h"

static void	put_grid(t_map *map)
{
	t_vec2i	coord;

	coord = (t_vec2i){0, 0};
	while (coord.y < map->column_height)
	{
		coord.x = 0;
		while (map->grid[coord.y][coord.x])
		{
			mlx_put_image_to_window(map->mlx, map->win, map->floor, \
												coord.x << 5, coord.y << 5);
			if (map->grid[coord.y][coord.x] == '1')
				mlx_put_image_to_window(map->mlx, map->win, map->wall, \
												coord.x << 5, coord.y << 5);
			if (map->grid[coord.y][coord.x] == 'C')
				mlx_put_image_to_window(map->mlx, map->win, map->collect->col, \
												coord.x << 5, coord.y << 5);
			coord.x++;
		}
		coord.y++;
	}
}

static void	put_player(t_map *map, int x, int y)
{
	mlx_put_image_to_window(map->mlx, map->win, map->player.player, \
												x << 5, y << 5);
}

void	render_loop(void *param)
{
	t_map	*map;

	map = (t_map *)param;
	mlx_clear_window(map->mlx, map->win, (mlx_color){.rgba = 0x00000000});
	put_grid(map);
	put_player(map, map->player.coords.x, map->player.coords.y);
	if (map->collected == lst_count_collect(&map->collect))
	{
		map->exit.winnable = 1;
		mlx_put_image_to_window(map->mlx, map->win, map->exit.i_e, \
						map->exit.coords.x << 5, map->exit.coords.y << 5);
	}
}
