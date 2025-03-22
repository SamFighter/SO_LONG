/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_engine.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salabbe <salabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 19:29:45 by salabbe           #+#    #+#             */
/*   Updated: 2025/03/22 19:29:49 by salabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_ENGINE_H
# define MLX_ENGINE_H

#include "structure.h"

typedef struct s_map	t_map;

void	window_hook(int event, void* param);
void	render_loop(void* param);
void	free_engine(t_map *map);

#endif