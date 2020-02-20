/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush-02.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchotel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 12:28:00 by jchotel           #+#    #+#             */
/*   Updated: 2019/08/18 23:22:48 by llaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "../includes/rush02.h"

#include <stdio.h>

int		ft_power_10(int power)
{
	int	result;

	result = 1;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	else
	{
		while (power > 0)
		{
			result = 10 * result;
			power--;
		}
		return (result);
	}
}

int		ft_rush(char *str, int *tab, int size, int i)
{
	int j;

	j = 0;
	while (str[++i])
	{
		if (size % 3 == 2 && str[i] != '0')
		{
			tab[j++] = (str[i] - 48);
			tab[j++] = 100;
		}
		if (size % 3 == 1 && str[i] != '0' && str[i] != '1')
			tab[j++] = ((str[i] - 48) * 10);
		if (size % 3 == 0)
		{
			if (str[i - 1] == '1')
				tab[j++] = str[i] - 38;
			else if (str[i] != 48)
				tab[j++] = str[i] - 48;
			if (size > 0 && (str[i - 2] != '0'
						|| str[i - 1] != '0' || str[i] != '0'))
				tab[j++] = ft_power_10(size);
		}
		size--;
	}
	return (j);
}

void	affichage(int *tab, int taille, char *dict)
{
	int i;

	i = -1;
	while (++i < taille)
	{
		ft_putstr(get_value_by_number(dict, ft_itoa(tab[i])));
		if (tab[i] >= 1000 && i != taille - 1 && BONUS)
			ft_putstr(", ");
		else if (tab[i] < 100 && tab[i] >= 20 && tab[i + 1] <= 9 &&
				tab[i + 1] >= 1 && i != taille - 1 && BONUS)
			ft_putstr("-");
		else if (((tab[i] == 100 || tab[i] == 1000 || tab[i] == 1000000) &&
					i != taille - 1 && BONUS && tab[i + 1] < 100))
			ft_putstr(" and ");
		else if (i != taille - 1)
			ft_putstr(" ");
	}
}

int		*ft_numbers(char *str, char *dict)
{
	int i;
	int *tab;
	int taille;
	int a;

	i = -1;
	a = -1;
	taille = ft_strlen(str) - 1;
	if (!(tab = malloc(sizeof(int) * ((taille * 2)))))
		return (0);
	if (ft_strcmp(str, "0") == 0)
		ft_putstr(get_value_by_number(dict, "0"));
	else
		affichage(tab, ft_rush(str, tab, taille, a), dict);
	return (tab);
}
