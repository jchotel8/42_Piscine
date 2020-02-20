/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchotel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 11:54:03 by jchotel           #+#    #+#             */
/*   Updated: 2019/08/06 12:13:59 by jchotel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_comb2(void)
{
	int nb1;
	int nb2;

	nb1 = -1;
	while (nb1++ <= 98)
	{
		nb2 = nb1;
		while (nb2++ <= 98)
		{
			ft_putchar(nb1 / 10 + 48);
			ft_putchar(nb1 % 10 + 48);
			ft_putchar(' ');
			ft_putchar(nb2 / 10 + 48);
			ft_putchar(nb2 % 10 + 48);
			if (nb1 < 98)
			{
				ft_putchar(',');
				ft_putchar(' ');
			}
		}
	}
}
