/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salabbe <salabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 11:36:06 by salabbe           #+#    #+#             */
/*   Updated: 2025/03/31 12:05:27 by salabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_H
# define STRUCTURE_H

# include "lst_collectible.h"
# include "lst_line.h"
# include "mlx_engine.h"
# include "../MacroLibX/includes/mlx.h"
# include "../MacroLibX/includes/mlx_extended.h"
# include "../MacroLibX/includes/mlx_profile.h"
# include "vec2i.h"

typedef struct s_lst_collectible	t_lst_collectible;

typedef struct s_player
{
	int			nb_player;
	t_vec2i		coords;
	mlx_image	player;
}				t_player;

typedef struct s_exit
{
	int			nb_exit;
	mlx_image	i_e;
	t_vec2i		coords;
	bool		winnable;
}				t_exit;
typedef struct s_map
{
	mlx_context				mlx;
	mlx_window				win;
	mlx_window_create_info	info;
	mlx_image				floor;
	mlx_image				wall;
	int						line_width;
	int						column_height;
	int						fd;
	int						collected;
	char					*path_name;
	char					**grid;
	t_player				player;
	t_exit					exit;
	t_lst_line				*lst_line;
	t_lst_collectible		*collect;
}							t_map;

typedef struct s_ff_count
{
	int		ff_co;
	int		ff_p;
	int		ff_e;
	int		ff_recur;
}			t_ff_count;

#endif