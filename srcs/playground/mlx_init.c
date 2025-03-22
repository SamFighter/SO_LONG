/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salabbe <salabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 18:46:12 by salabbe           #+#    #+#             */
/*   Updated: 2025/03/19 19:03:45 by salabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"
#include <stdio.h>

void    init_mlx_var(t_map *map)
{
    map->mlx = mlx_init();
    map->info.render_target = (mlx_image){0};
	printf("map->info.width = %d\n", map->info.width);
	printf("map->info.height = %d\n", map->info.height);
	map->info.is_fullscreen = 0;
	map->info.is_resizable = 0;
    map->info.title = "SO_LONG";
    map->win = mlx_new_window(map->mlx, &map->info);
}