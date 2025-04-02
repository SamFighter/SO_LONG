/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salabbe <salabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 17:18:24 by salabbe           #+#    #+#             */
/*   Updated: 2025/04/02 15:28:16 by salabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static int	check_count_map(t_ff_count *ff_c, char c)
{
	if (c == '1' || c == '0')
		return (1);
	else if (c == 'E')
	{
		ff_c->ff_e++;
		return (1);
	}
	else if (c == 'P')
	{
		ff_c->ff_p++;
		return (1);
	}
	else if (c == 'C')
	{
		ff_c->ff_co--;
		return (1);
	}
	else
		return (0);
}

char	**copy_map(t_map *map)
{
	char	**cpy;
	int		y;

	cpy = ft_calloc(map->column_height + 1, sizeof(char *));
	if (!cpy)
		return (NULL);
	y = 0;
	while (y < map->column_height)
	{
		cpy[y] = ft_strdup(map->grid[y]);
		y++;
	}
	return (cpy);
}

int	check_count(t_map *map, t_ff_count *ff_count)
{
	if (ff_count->ff_co != 0)
		return (0);
	if (ff_count->ff_e != map->exit.nb_exit)
		return (0);
	if (ff_count->ff_p != map->player.nb_player)
		return (0);
	else
		return (1);
}

void	flood_fill(char **cpy, int x, int y, t_ff_count *ff_count)
{
	if (ff_count->ff_recur >= 100000)
		return ;
	ff_count->ff_recur++;
	check_count_map(ff_count, cpy[y][x]);
	cpy[y][x] = '1';
	if (cpy[y + 1][x] != '1')
		flood_fill(cpy, x, (y + 1), ff_count);
	if (cpy[y - 1][x] != '1')
		flood_fill(cpy, x, (y - 1), ff_count);
	if (cpy[y][x + 1] != '1')
		flood_fill(cpy, (x + 1), y, ff_count);
	if (cpy[y][x - 1] != '1')
		flood_fill(cpy, (x - 1), y, ff_count);
	else
		return ;
}
