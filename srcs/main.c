/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salabbe <salabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 14:33:47 by salabbe           #+#    #+#             */
/*   Updated: 2025/03/23 11:18:42 by salabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"


static int	check_file_name(char *file_name)
{
	int	i;

	i = 0;
	while (file_name[i])
	{
		if (ft_isspace(file_name[i]))
		{
			ft_printf("File name incorrect, space not allowed\n");
			return (0);
		}
		if (!ft_strstr(file_name, ".ber"))
		{
			ft_printf("The file is not a .ber\n");
			return (0);
		}
		if (ft_strlen(file_name) == 14)
		{
			ft_printf("File name incorrect\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_map	map;
	int		height = 0;
	int		width = 0;

	if (ac != 2)
	{
		ft_printf("Number of argument isn't correct, try with file.ber\n");
		return (0);
	}
	ft_bzero(&map,sizeof(map));
	check_file_name(av[1]);
	(&map)->path_name = av[1];
	check_map(&map);
	init_mlx_var(&map);
	map.floor = mlx_new_image_from_file(map.mlx, "assets/floor.png",&width, &height);
	map.wall = mlx_new_image_from_file(map.mlx, "assets/wall.png",&width, &height);
	map.player.player = mlx_new_image_from_file(map.mlx, "assets/player.png", &width, &height);

	mlx_on_event(map.mlx, map.win, MLX_WINDOW_EVENT, window_hook, &map);
	mlx_add_loop_hook(map.mlx, render_loop, &map);
    mlx_loop(map.mlx);

	free_map(&map);
	free_engine(&map);
}