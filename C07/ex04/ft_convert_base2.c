/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchotel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 18:30:44 by jchotel           #+#    #+#             */
/*   Updated: 2019/08/22 10:53:11 by jchotel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str);
int		ft_atoi_base(char *str, char *base);
int		check_base (char *base);

int		value(long int nbr, char *base)
{
	int i;

	i = 1;
	while (nbr / ft_strlen(base) > 0)
	{
		nbr /= ft_strlen(base);
		i++;
	}
	return (i);
}

char	*ft_itoa_base(int nbr, char *base)
{
	int			i;
	int			sign;
	long int	tmp;
	char		*res;
	long int	val;

	val = nbr;
	sign = (nbr < 0) ? 1 : 0;
	if (nbr < 0)
		val = -val;
	tmp = val;
	i = value(tmp, base);
	if (!(res = (char *)malloc(sizeof(char) * (i + 1))))
		return (0);
	while (i-- > 0)
	{
		res[i + sign] = base[val % ft_strlen(base)];
		val /= ft_strlen(base);
	}
	if (sign)
		res[0] = '-';
	res[value(tmp, base) + sign] = 0;
	return (res);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int nb;

	if (check_base(base_from) == 0 || check_base(base_to) == 0)
		return (NULL);
	nb = ft_atoi_base(nbr, base_from);
	return (ft_itoa_base(nb, base_to));
}
