/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salabbe <salabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 14:33:47 by salabbe           #+#    #+#             */
/*   Updated: 2025/03/22 14:50:04 by salabbe          ###   ########.fr       */
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

	if (ac != 2)
	{
		ft_printf("Number of argument isn't correct, try with file.ber\n");
		return (0);
	}
	ft_bzero(&map,sizeof(map));
	check_file_name(av[1]);
	(&map)->path_name = av[1];
	check_map(&map);
	// init_mlx_var(&map);
	free_map(&map);
}