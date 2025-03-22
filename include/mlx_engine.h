/*
 * Filename: /nfs/homes/ygaiffie/Documents/solong_salabbe/include/mlx_engine.h
 * Path: /nfs/homes/ygaiffie/Documents/solong_salabbe/include
 * Created Date: Thursday, January 1st 1970, 1:00:00 am
 * Author: Yohann Gaiffier
 * 
 * Copyright (c) 2025 Your Company
 */

#ifndef MLX_ENGINE_H
# define MLX_ENGINE_H

#include "structure.h"

typedef struct s_map	t_map;

void	window_hook(int event, void* param);
void	render_loop(void* param);
void	free_engine(t_map *map);

#endif