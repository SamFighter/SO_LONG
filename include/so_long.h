/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salabbe <salabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 10:00:10 by salabbe           #+#    #+#             */
/*   Updated: 2025/03/22 14:44:58 by salabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	SO_LONG_H
# define SO_LONG_H

#include "../libft/INCLUDES/libft.h"
#include "../libft/INCLUDES/get_next_line.h"
#include "../libft/INCLUDES/ft_printf.h"
#include "../MacroLibX/includes/mlx.h"
#include "../MacroLibX/includes/mlx_extended.h"
#include "../MacroLibX/includes/mlx_profile.h"
#include "structure.h"
#include "lst_line.h"
#include "lst_collectible.h"
#include "mlx_engine.h"

#include <fcntl.h>
#include <stdlib.h>

#define WIDTH_WIN 1920
#define HEIGHT_WIN 1080
#define TILE_SIZE 32

////////////////////////////////FUNCTIONS////////////////////////////////////////

void    len_grid(t_map *map);
void    check_map(t_map *map);
char    **copy_map(t_map *map);
int     check_count(t_map *map, t_ff_count *ff_count);
void    flood_fill(char **cpy, int x, int y, t_ff_count *ff_count);

////////////////////////////////UTILS////////////////////////////////////////////

int     line_len(char *line);
int	    lstsize(t_lst_line *lst);

////////////////////////////////ERROR////////////////////////////////////////////

void    free_map(t_map *map);
void	free_cpy(char **cpy);
void	ft_return(t_map *map, char **cpy, char *msg);

void    init_mlx_var(t_map *map);
void	render_loop(void* param);

#endif