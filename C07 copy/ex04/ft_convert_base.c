/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchotel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 18:30:44 by jchotel           #+#    #+#             */
/*   Updated: 2019/08/21 20:25:29 by jchotel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		nbr_size(int nbr, char *base)
{
	int size;
	int base_size;

	size = 0;
	base_size = 0;
	while (base[base_size])
		base_size++;
	while (nbr >= base_size)
	{
		size++;
		nbr = nbr / base_size;
	}
	return (size);
}

int		ft_print_nbr_base(int nb, char *str, char *result, int end)
{
	unsigned int	nbr;
	unsigned int	str_size;

	str_size = 0;
	while (str[str_size])
		str_size++;
	if (nb < 0)
	{
		result[end++] = '-';
		nbr = nb * -1;
	}
	else
		nbr = nb;
	if (nbr >= str_size)
		ft_print_nbr_base(nbr / str_size, str, result, end - 1);
	result[end] = str[nbr % str_size];
	return (end);
}

int		ft_getbase(char c, char *base)
{
	int i;

	i = 0;
	while (base[i] && base[i] != c)
		i++;
	return (i);
}

int		ft_atoi_base(char *str, char *base)
{
	int j;
	int i;
	int res;
	int negative;
	int base_size;

	base_size = 0;
	res = 0;
	negative = 1;
	while (base[base_size])
		base_size++;
	j = 0;
	while (str[j] != '\0' && (str[j] == ' ' || str[j] == '\t' || str[j] == '\r'
				|| str[j] == '\n' || str[j] == '\v' || str[j] == '\f'))
		j++;
	i = j - 1;
	while (str[++i] && (((str[i] == '-' || str[i] == '+') && i == j) ||
				(str[i] != '-' && str[i] != '+')))
		if (str[i] == '-')
			negative = -1;
		else if (str[i] != '+')
			res = (res * base_size) + (ft_getbase(str[i], base));
	return (res * negative);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*result;
	int		nint;
	int		end;

	if (!nbr || !base_from || !base_to)
		return (0);
	nint = ft_atoi_base(nbr, base_from);
	result = malloc(sizeof(char) * get_number_length(nint, base_to));
	end = ft_print_nbr_base(nint, base_to, result,
			get_number_length(nint, base_to) - 1);
	result[end + 1] = '\0';
	return (result);
}

int		main(int argc, const char *argv[])
{
	printf("%s\n", ft_convert_base(argv[1], argv[2], argv[3]));
	return (0);
}
