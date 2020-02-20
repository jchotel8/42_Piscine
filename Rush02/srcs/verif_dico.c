/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_dico.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 13:55:26 by llaurent          #+#    #+#             */
/*   Updated: 2019/08/18 23:13:19 by llaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rush02.h"
#include <stdio.h>

int	compare(char *s1, char *s2, int number)
{
	int	index;

	index = 0;
	while (index < number)
	{
		if (!s1[index] || !s2[index])
			return (0);
		if (s1[index] != s2[index])
			return (0);
		index++;
	}
	return (1);
}

int	dico_is_valid(char *dict, char *sample)
{
	char	**splitted;
	int		index;

	sample = get_dico(sample);
	splitted = ft_split(sample, "\n");
	index = 0;
	while (splitted[index])
	{
		if (ft_strstr(dict, splitted[index]) == NULL ||
				compare(splitted[index],
					ft_strstr(dict, splitted[index]),
					ft_strlen(splitted[index])) != 1)
			return (0);
		index++;
	}
	return (1);
}
