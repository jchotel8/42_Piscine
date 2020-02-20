/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchotel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 05:04:14 by jchotel           #+#    #+#             */
/*   Updated: 2019/08/15 01:02:32 by jchotel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr_base_rec(long nbr, int i, char *base)
{
	int mod;
	int min;

	min = 0;
	if (nbr > i)
	{
		ft_putnbr_base_rec(nbr / i, i, base);
		mod = nbr % i;
		ft_putchar(base[mod]);
	}
	else
	{
		if (min == 1)
			nbr = nbr + 1;
		ft_putchar(base[nbr]);
	}
}

int		check_base(char *base)
{
	int i;
	int k;
	int j;

	i = 0;
	k = 0;
	while (base[i] != '\0')
	{
		if (base[i] <= 32 || base[i] == 43 || base[i] == 45)
			return (0);
		i++;
	}
	while (k != i)
	{
		j = k + 1;
		while (j != i)
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		k++;
	}
	return (i);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int			sign;
	int			taille;
	long int	val;

	sign = 1;
	taille = check_base(base);
	val = (long)nbr;
	if (val < 0)
	{
		ft_putchar('-');
		val *= -1;
	}
	if (taille > 1)
		ft_putnbr_base_rec(val, taille, base);
}
