/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_collectible.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salabbe <salabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 11:02:47 by salabbe           #+#    #+#             */
/*   Updated: 2025/03/31 11:50:44 by salabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LST_COLLECTIBLE_H
# define LST_COLLECTIBLE_H

# include "../libft/INCLUDES/libft.h"
# include "../libft/INCLUDES/get_next_line.h"
# include "../libft/INCLUDES/ft_printf.h"
# include "vec2i.h"
# include "mlx_engine.h"

typedef struct s_lst_collectible
{
	t_vec2i						coord;
	mlx_image					col;
	struct s_lst_collectible	*next;
	struct s_lst_collectible	*prev;
}								t_lst_collectible;

t_lst_collectible	*insert_end_lst_collectible(t_lst_collectible **head, \
					t_vec2i coord);
void				delete_node_lst_collectible(t_lst_collectible **head, \
					t_lst_collectible *del_node);
void				delete_all_lst_collectible(t_lst_collectible **head);
int					lst_count_collect(t_lst_collectible **lst);

#endif