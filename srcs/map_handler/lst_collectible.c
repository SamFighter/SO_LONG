/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_collectible.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salabbe <salabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 10:58:12 by salabbe           #+#    #+#             */
/*   Updated: 2025/03/31 12:12:24 by salabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/lst_collectible.h"
#include "../../include/structure.h"

t_lst_collectible	*insert_end_lst_collectible(t_lst_collectible **head, \
												t_vec2i coord)
{
	t_lst_collectible	*new_node;
	t_lst_collectible	*tmp_node;

	tmp_node = *head;
	new_node = (t_lst_collectible *)malloc(sizeof(t_lst_collectible));
	if (new_node == NULL)
		return (NULL);
	new_node->coord = coord;
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

void	delete_node_lst_collectible(t_lst_collectible **head, \
									t_lst_collectible *del_node)
{
	if (*head == NULL || del_node == NULL)
		return ;
	if (*head == del_node)
		*head = del_node->next;
	if (del_node->next != NULL)
		del_node->next->prev = del_node->prev;
	if (del_node->prev != NULL)
		del_node->prev->next = del_node->next;
	free(del_node);
	del_node = NULL;
}

void	delete_all_lst_collectible(t_lst_collectible **head)
{
	if (*head == NULL)
		return ;
	while (*head != NULL)
		delete_node_lst_collectible(head, *head);
}

int	lst_count_collect(t_lst_collectible **lst)
{
	t_lst_collectible	*tmp;
	int					size;

	tmp = *lst;
	size = 0;
	while (tmp)
	{
		size++;
		tmp = tmp->next;
	}
	return (size);
}
