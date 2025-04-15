/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salabbe <salabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 18:46:12 by salabbe           #+#    #+#             */
/*   Updated: 2025/04/14 18:41:42 by salabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	init_mlx_var(t_map *map)
{
	map->mlx = mlx_init();
	map->info.render_target = (mlx_image){0};
	map->info.is_fullscreen = 0;
	map->info.is_resizable = 0;
	map->info.title = "SO_LONG";
	map->win = mlx_new_window(map->mlx, &map->info);
}

void check_img(char *str)
{
	int	fd;

	if (str == NULL)
		ft_return(NULL, NULL, "Error with check_img");
	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Unable to open %s\n", str);
		exit (1);
	}
	close(fd);
}

void  check_all_img()
{
	check_img("assets/coin.png");
	check_img("assets/player.png");
	check_img("assets/exit.png");
	check_img("assets/wall.png");
	check_img("assets/floor.png");
}
