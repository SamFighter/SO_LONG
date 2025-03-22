/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salabbe <salabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 11:12:09 by salabbe           #+#    #+#             */
/*   Updated: 2025/02/28 11:44:42 by salabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/libft.h"

int	ft_putstr(const char *str)
{
	int		i;

	i = 0;
	if (!str)
	{
		i += write(1, "(null)", 6);
		return (i);
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}