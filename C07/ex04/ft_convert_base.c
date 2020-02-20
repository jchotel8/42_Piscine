/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchotel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 18:30:44 by jchotel           #+#    #+#             */
/*   Updated: 2019/08/22 10:50:56 by jchotel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		position(char str, char *base)
{
	int i;

	i = 0;
	while (base[i])
	{
		if (str == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int		ft_is_in_base(char str, char *base)
{
	while (*base)
	{
		if (str == *base)
			return (1);
		base++;
	}
	return (0);
}

int		check_base(char *base)
{
	int i;
	int j;

	i = 0;
	while (base[i])
	{
		j = i + 1;
		if (base[i] == '+' || base[i] == '-')
			return (0);
		if (base[i] <= 32)
			return (0);
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	if (i < 2)
		return (0);
	return (1);
}

int		ft_atoi_base(char *str, char *base)
{
	int negative;
	int res;

	res = 0;
	negative = 1;
	if (check_base(base))
	{
		while (*str == ' ' || *str == '\t' || *str == '\r'
				|| *str == '\n' || *str == '\v' || *str == '\f')
			str++;
		while (*str == '-' || *str == '+')
		{
			if (*str == '-')
				negative = -negative;
			str++;
		}
		while (ft_is_in_base(*str, base) && *str)
		{
			res = res * ft_strlen(base) + position(*str, base);
			str++;
		}
		return (res * negative);
	}
	return (0);
}
