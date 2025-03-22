# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: salabbe <salabbe@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/24 18:41:03 by salabbe           #+#    #+#              #
#    Updated: 2025/03/19 18:55:15 by salabbe          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

N_NAME		= so_long

# **************************************************************************** #
#								    										   #
#				=======>		INGREDIENTS			<=======		   		   #
#																			   #
# **************************************************************************** #

LIBFT 		= ./libft/libft.a

MANDATORY	= 	srcs/main.c								\
				srcs/map_handler/map_pars.c				\
				srcs/map_handler/map_pars2.c			\
				srcs/map_handler/flood_fill.c			\
				srcs/map_handler/lst_line.c				\
				srcs/map_handler/lst_collectible.c		\
				srcs/map_handler/free_error.c			\
				srcs/playground/map_init.c				\

N_OBJS		=	$(MANDATORY:%.c=.build/%.o)
DEPS		=	$(N_OBJS:%.o=%.d)

CC			=	clang
CFLAGS		=	-Wall -Wextra -Werror -g
CPPFLAGS	=	-MP	-MMD -Iinclude -Iinclude/so_long.h -Ilibft/INCLUDES/libft.h	\
				-Iinclude/structure.h -Iinclude/lst_line.h -I/usr/include -Imlx	\
				-Iinclude/lst_collectible.h -Iinclude/vec2i.h 					\

MLX			=	MacroLibX/libmlx.so

MLX_FLAGS 	=	-lSDL2 -lm
				
LDFLAGS		=	-Llibft -lft

# **************************************************************************** #
#								    										   #
#			    	=======>		TOOLS			<=======		   		   #
#																			   #
# **************************************************************************** #

MAKEFLAGS	+=	--silent --no-print-directory

# **************************************************************************** #
#								    										   #
#			    	=======>		RECIPES			<=======		   		   #
#																			   #
# **************************************************************************** #

all:	 $(N_NAME)

$(N_NAME): $(LIBFT) $(N_OBJS)
		$(CC) $(CFLAGS) $(N_OBJS) $(LDFLAGS) -o $(N_NAME) $(MLX_FLAGS) $(MLX)
		$(info CREATED $(N_NAME))

$(LIBFT):
		$(MAKE) -C libft

.build/%.o: %.c
		mkdir -p $(@D)
		$(CC) $(CFLAGS) -c $(CPPFLAGS) $< -o $@
		$(info CREATED $@)

-include $(DEPS)

clean:
		$(MAKE) -C libft clean
		rm -rf .build

fclean: clean
		$(MAKE) -C libft fclean
		rm -rf $(N_NAME)

re:
		$(MAKE) fclean
		$(MAKE) all

# **************************************************************************** #
#								    										   #
#			    	=======>		PIMPER			<=======		   		   #
#																			   #
# **************************************************************************** #

OFF			:= \033[0m
RED			:= \033[0;31m
GREEN		:= \033[0;32m
YELLOW		:= \033[0;33m
CYAN		:= \033[0;36m
PURPLE		:= \033[0;35m
