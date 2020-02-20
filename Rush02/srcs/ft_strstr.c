/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 15:02:51 by llaurent          #+#    #+#             */
/*   Updated: 2019/08/03 15:54:08 by llaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	unsigned int	index;
	unsigned int	to_find_counter;
	unsigned int	index2;

	index = 0;
	to_find_counter = 0;
	while (to_find[to_find_counter])
		to_find_counter++;
	if (!to_find_counter)
		return (&str[index]);
	while (str[index])
	{
		index2 = 0;
		while (to_find[index2] == str[index + index2])
		{
			if (index2 == to_find_counter - 1)
			{
				return (&str[index]);
			}
			index2++;
		}
		index++;
	}
	return (0);
}
