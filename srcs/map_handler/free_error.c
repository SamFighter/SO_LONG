/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salabbe <salabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 17:03:11 by salabbe           #+#    #+#             */
/*   Updated: 2025/03/22 19:29:19 by salabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	free_cpy(char **cpy)
{
	int	y;

	y = 0;
	if (!cpy)
		return ;
	while (cpy[y])
	{
        if (cpy[y])
		    free(cpy[y]);
		y++;
	}
	if (cpy)
		free(cpy);
}

void	ft_return(t_map *map, char **cpy, char *msg)
{
	ft_printf("Error\n");
	ft_printf("%s\n", msg);
	free_cpy(cpy);
	free_map(map);
}

void    free_map(t_map *map)
{
	delete_all_lst_line(&map->lst_line);
	free(map->grid);
	delete_all_lst_collectible(&map->collect);
    exit (0);
}

