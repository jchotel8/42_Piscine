/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchotel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 13:44:42 by jchotel           #+#    #+#             */
/*   Updated: 2019/08/04 21:59:36 by jchotel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_condition(int nb, int flag[2])
{
	if (nb == -2147483648)
	{
		nb++;
		flag[0] = 1;
	}
	if (nb < 0)
	{
		nb = nb * -1;
		ft_putchar('-');
	}
	return (nb);
}

void	ft_putnbr(int nb)
{
	int max;
	int q;
	int flag[2];

	max = 1000000000;
	flag[0] = 0;
	flag[1] = 0;
	nb = ft_condition(nb, flag);
	while (max > 1)
	{
		q = nb / max;
		nb = nb % max;
		max = max / 10;
		if (q != 0)
			flag[1] = 1;
		if (flag[1] == 1)
			ft_putchar(q + 48);
	}
	if (flag[0] == 1)
		nb++;
	ft_putchar(nb + 48);
}

int     main (int ac, char **av)
{
    ft_putnbr(atoi(av[1]));
    return (0);
}
