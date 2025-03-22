/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salabbe <salabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 10:58:12 by salabbe           #+#    #+#             */
/*   Updated: 2025/03/22 19:29:24 by salabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/lst_line.h"

t_lst_line	*insert_end_lst_line(t_lst_line **head, char *line, size_t line_len)
{
	t_lst_line	*new_node;
	t_lst_line	*tmp_node;

	tmp_node = *head;
	new_node = (t_lst_line *)malloc(sizeof(t_lst_line));
	if (new_node == NULL)
		return (NULL);
	new_node->line = line;
    new_node->line_len = line_len;
	new_node->next = NULL;
	if (*head == NULL)
	{
		new_node->prev = NULL;
		*head = new_node;
		return (new_node);
	}
	while (tmp_node->next != NULL)
		tmp_node = tmp_node->next;
	tmp_node->next = new_node;
	new_node->prev = tmp_node;
	return (new_node);
}

void	delete_node_lst_line(t_lst_line **head, t_lst_line *del_node)
{
	if (*head == NULL || del_node == NULL)
		return ;
	if (*head == del_node)
		*head = del_node->next;
	if (del_node->next != NULL)
		del_node->next->prev = del_node->prev;
	if (del_node->prev != NULL)
		del_node->prev->next = del_node->next;
	free(del_node->line);
    del_node->line = NULL;
	free(del_node);
	del_node = NULL;
}

void	delete_all_lst_line(t_lst_line **head)
{
	if (*head == NULL)
		return ;
	while (*head != NULL)
		delete_node_lst_line(head, *head);
}

void	replace_eol_to_nul(char *str)
{
	while (*str != '\0')
	{
		if (*str == '\n')
			*str = '\0';
		str++;
	}
}
