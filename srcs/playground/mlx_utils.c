/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salabbe <salabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 19:33:16 by salabbe           #+#    #+#             */
/*   Updated: 2025/03/22 19:33:35 by salabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void window_hook(int event, void* param)
{
	t_map *map;
	
	map = (t_map*)param;
	if(event == 0)
		mlx_loop_end(map->mlx);
}

void free_engine(t_map *map)
{
	mlx_destroy_window(map->mlx, map->win);
	mlx_destroy_image(map->mlx, map->floor);
	mlx_destroy_context(map->mlx);
}