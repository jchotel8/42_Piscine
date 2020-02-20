/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchotel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 18:15:29 by jchotel           #+#    #+#             */
/*   Updated: 2019/08/15 00:40:27 by jchotel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		check_base(char *base)
{
	int i;
	int j;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == ' ' || base[i] == '+' || base[i] == '-' || base[i] == '\t'
				|| base[i] == '\n' || base[i] == '\r' || base[i] == '\v'
				|| base[i] == '\f')
			return (0);
		j = 0;
		while (j != i)
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

int		calcul_base(char *str, char *base, int taille, int i)
{
	int j;
	int result;

	j = 0;
	result = 0;
	while (str[i])
	{
		while (str[i] != base[j])
		{
			if (j == taille - 1)
				return (0);
			j++;
		}
		result = result * taille + j;
		i++;
		j = 0;
	}
	return (result);
}

int		ft_atoi_base(char *str, char *base)
{
	int sign;
	int taille;
	int result;
	int i;

	i = 0;
	sign = 1;
	result = 0;
	taille = check_base(base);
	while (str[i] == 32 || str[i] == '\t' || str[i] == '\n' ||
			str[i] == '\r' || str[i] == '\v' || str[i] == '\f')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	return (calcul_base(str, base, taille, i) * sign);
}
