/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush-02.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchotel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 12:28:00 by jchotel           #+#    #+#             */
/*   Updated: 2019/08/18 16:33:37 by llaurent         ###   ########.fr       */
/*   Updated: 2019/08/17 18:05:16 by llaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rush02.h"
#include <unistd.h>

int         ft_iterative_power(int nb, int power)
{
	int     result;

	result = 1;
	if ((nb == 0 && power !=0) || power < 0)
		return (0);
	if ((power == 0) || (( nb < 0) && (power == 0)))
		return (1);
	else
	{
		while (power > 0)
		{
			result =  nb * result;
			power--;
		}
		return (result);
	}
}

void ft_rush02(char *nbr, char *dict)
{
	int i;
	int taille;
	int key;
	int pos;

	taille = ft_strlen(nbr);
	key = 10;
	i = 0;

	while(nbr[i] == '0')
	{
		if (i == taille)
			ft_putstr(get_value_by_number(dict, "0"));
		i++;
	}

	//CALCULER LE RANG POUR CHAQUE CHIFFRE
	while (nbr[i])
	{
		pos = taille - i - 1;
		if (pos % 3 == 2 && nbr[i] != '0')
		{//affiche la valeur des centaines
			key = nbr[i] - 48;
			ft_putstr(get_value_by_number(dict, ft_itoa(key)));
			ft_putstr(" ");
		}
		//calcul le rang
		key = ft_iterative_power(10, pos % 3);
		if ((pos % 3 == 1 && nbr[i] != '1') || pos % 3 == 0)
		{//affiche les dizaines et les unités
			key = key * (nbr[i] - 48);
		}
		if (pos % 3 == 1 && nbr[i] == '1')
		{//affiche de 10 a 19
			i++;
			key = key + (nbr[i] - 48);
		}
		pos = taille - i - 1;
		if (nbr[i] != '0' || key == 10 || taille == 1)
		{
			ft_putstr(get_value_by_number(dict, ft_itoa(key)));
			ft_putstr(" ");
		}
		if(pos % 3 == 0 && pos != 0)
		{//affiche le rang des 10^3*x
			key = ft_iterative_power(10, pos);
			if (nbr[i-2] != '0' || nbr[i - 1] != '0' || nbr[i] != '0')
				ft_putstr(get_value_by_number(dict, ft_itoa(key)));
				ft_putstr(" ");
			if (pos != 0 && (nbr[i + 3] != '0' || nbr[i + 2] != '0' || nbr[i + 1] != '0')) //et condition si que des zéros derrières
				ft_putstr(", ");
		}
		i++;
	}
}
