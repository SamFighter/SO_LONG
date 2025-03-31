/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_line.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salabbe <salabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 11:02:47 by salabbe           #+#    #+#             */
/*   Updated: 2025/03/31 12:06:33 by salabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LST_LINE_H
# define LST_LINE_H

# include "../libft/INCLUDES/libft.h"
# include "../libft/INCLUDES/get_next_line.h"
# include "../libft/INCLUDES/ft_printf.h"

typedef struct s_lst_line
{
	size_t				line_len;
	char				*line;
	struct s_lst_line	*next;
	struct s_lst_line	*prev;
}						t_lst_line;

t_lst_line			*insert_end_lst_line(t_lst_line **head, \
					char *line, size_t line_len);
void				delete_node_lst_line(t_lst_line **head, \
					t_lst_line *del_node);
void				delete_all_lst_line(t_lst_line **head);
void				replace_eol_to_nul(char *str);

#endif