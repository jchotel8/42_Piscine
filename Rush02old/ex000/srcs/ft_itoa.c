/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 16:58:42 by llaurent          #+#    #+#             */
/*   Updated: 2019/08/17 17:01:00 by llaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *tab)
{
	int	i;

	i = 0;
	while(tab[i] != '\0')
	{
		i++;
	}
	return (i);
}


char	*ft_itoa(int nbr)
{
	int			i;
	long int	nb;
	int			size;
	int			less;
	char		*tab;
	char		temp;

	i = 0;
	tab = malloc(sizeof(char) * nbr);
	if (nbr < 0)
	{
		nb = nbr * (-1);
		less = 1;
	}
	else
		nb = nbr;
	while(nb > 9)
	{
		tab[i] = (nb % 10 + 48);
		nb = nb / 10;
		i++;
	}

	tab[i] = (nb % 10 + 48);
	i++;
	tab[i] = '\0';
		if (less == 1)
			tab[i + 1] = '-';
	size = ft_strlen(tab);
	i = 0;
	while (i < (size / 2))
	{
		temp = tab[i];
		tab[i] = tab[size - i - 1];
		tab[size - i - 1] = temp;
		i++;
	}
	return(tab);
}
