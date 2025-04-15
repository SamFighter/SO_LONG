/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_start_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salabbe <salabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 19:01:04 by salabbe           #+#    #+#             */
/*   Updated: 2025/04/15 11:44:07 by salabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_str_start_str(char *str, char *to_find, int start)
{
	int	i;
	int	j;

	i = start;
	if (to_find[0] == '\0')
		return (str);
	while (str[i])
	{
		j = 0;
		while (str[j + i] && to_find[j] == str[j + i])
		{
			if (to_find[j + 1] == '\0')
			{
				return (str + i);
			}
			j++;
		}
		i++;
	}
	return (0);
}
