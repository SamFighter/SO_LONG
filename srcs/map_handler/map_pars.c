/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_pars.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salabbe <salabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 11:19:51 by salabbe           #+#    #+#             */
/*   Updated: 2025/03/22 14:49:21 by salabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static void	init_grid(t_map *map)
{
	int y;
	t_lst_line	*tmp;

	len_grid(map);
	y = 0;
	tmp = map->lst_line;
	map->grid = ft_calloc(map->column_height + 1, sizeof(char *));
	if (!map->grid)
		return ;
	while (y != map->column_height)
	{
		map->grid[y] = tmp->line;
		y++;
		tmp = tmp->next;
	}
}

static int	check_pixel_map(t_map *map, t_vec2i coord)
{
	char c;

	c = map->grid[coord.y][coord.x];
	if (c == '1' || c == '0')
		return (1);
	else if (c == 'E')
	{
		map->exit.nb_exit++;
		map->exit.coords = (t_vec2i){coord.x , coord.y};
		return (1);
	}
	else if (c == 'P')
	{
		map->player.nb_player++;
		map->player.coords = (t_vec2i){coord.x , coord.y};
		return (1);
	}
	else if (c == 'C')
	{
		insert_end_lst_collectible(&map->collect, coord);
		return (1);
	}
	else
		return (0);
}

static void	count_gen_map(t_map *map)
{
	t_vec2i coord;

	coord = (t_vec2i){0 , 0};
	while (coord.y < map->column_height)
	{
		coord.x = 0;
		while (map->grid[coord.y][coord.x])
		{
			if (check_pixel_map(map, coord) == 0)
				ft_return(map, NULL, "Wrong map generation, only allowed : 1,0,P,E,C.");
			if (map->exit.nb_exit > 1)
				ft_return(map, NULL, "Too much exit in map.");
			if (map->player.nb_player > 1)
				ft_return(map, NULL, "It's not a multiplayer game, only one player allowed");
			coord.x++;
		}
		coord.y++;
	}
	if (map->player.nb_player == 0)
		ft_return(map, NULL, "Not any player");
	if (lst_count_collect(&map->collect) == 0 || map->exit.nb_exit == 0)
		ft_return(map, NULL, "Map can't be finished");
}
static void	check_borders(t_map *map)
{
	int	x;
	int	y;
	int	len_y;
	int	len_x;

	x = 0;
	y = 0;
	len_x = map->line_width;
	len_y = map->column_height;
	while (y < len_y)
	{
		if (map->grid[y][0] != '1')
			ft_return(map, NULL, "Border Invalid, expected '1'");
		if (map->grid[y][len_x - 1] != '1')
			ft_return(map, NULL, "Border Invalid, expected '1'");
		y++;
	}
	while (x < len_x)
	{
		if (map->grid[0][x] != '1')
			ft_return(map, NULL, "Border Invalid, expected '1'");
		if (map->grid[len_y - 1][x] != '1')
			ft_return(map, NULL, "Border Invalid, expected '1'");
		x++;
	}
}

void	check_map(t_map *map)
{
	char **cpy;
	t_ff_count ff_count;

	ft_bzero(&ff_count, sizeof(ff_count));
	init_grid(map);
	count_gen_map(map);
	check_borders(map);
	ff_count.ff_co = lst_count_collect(&map->collect);
	cpy = copy_map(map);
	flood_fill(cpy, map->player.coords.x, map->player.coords.y, &ff_count);
	if (ff_count.ff_recur >= 100000)
		ft_return(map, cpy, "Too much recursivity");
	if (check_count(map, &ff_count) == 0)
		ft_return(map, cpy, "Map not winable");
	free_cpy(cpy);
	// free_map(map);
}
