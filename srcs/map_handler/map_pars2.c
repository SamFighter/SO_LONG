/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_pars2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salabbe <salabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 17:11:45 by salabbe           #+#    #+#             */
/*   Updated: 2025/03/19 14:36:42 by salabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void file_to_lst_line(t_map *map)
{
	char	*line;
	size_t	line_len;

	map->fd = open(map->path_name, O_RDONLY);
	if (map->fd < 0)
		ft_return(map, NULL, "Map unkown or not accessible");
	line = get_next_line(map->fd);
	if (line == NULL)
		ft_return(map, NULL, "Empty file");
	while (line != NULL)
	{
		replace_eol_to_nul(line);
		line_len = ft_strlen(line);
		if (insert_end_lst_line(&map->lst_line, line, line_len) == NULL)
		{
			delete_all_lst_line(&map->lst_line);
			ft_printf("Error on line: %s\n", line);
			free(line);
			return ;
		}
		line = get_next_line(map->fd);
	}
	close(map->fd);
}

void len_grid(t_map *map)
{
	int	linelen;
	t_lst_line	*tmp;

	file_to_lst_line(map);
	tmp = map->lst_line;
	map->line_width = line_len(map->lst_line->line);
	while (tmp->next)
	{
		linelen = line_len(tmp->line);
		if (linelen != map->line_width)
			ft_return(map, NULL, "Map not rectangular !");
		tmp = tmp->next;
	}
	map->column_height = lstsize(map->lst_line);
}

int	line_len(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	return (i);
}

int	lstsize(t_lst_line *lst)
{
	int		size;

	size = 0;
	while (lst)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}
