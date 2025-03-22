/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salabbe <salabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 18:46:12 by salabbe           #+#    #+#             */
/*   Updated: 2025/03/19 19:03:45 by salabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static void window_hook(int event, void* param)
{
    if(event == 0)
        mlx_loop_end((mlx_context)param);
}

void    init_mlx_var(t_map *map)
{
    mlx_context mlx;
    mlx_window  win;
    mlx_window_create_info info;

    mlx = mlx_init();
    info = (mlx_window_create_info){0};
    info.height = HEIGHT_WIN;
    info.width = WIDTH_WIN;
    info.title = "SO_LONG";
    win = mlx_new_window(mlx, &info);
    mlx_on_event(mlx, win, MLX_WINDOW_EVENT, window_hook, mlx);
    mlx_loop(mlx);
    (void) map;
}