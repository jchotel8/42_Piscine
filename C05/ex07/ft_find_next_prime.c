/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchotel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 11:44:02 by jchotel           #+#    #+#             */
/*   Updated: 2019/08/18 04:03:39 by jchotel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int div;

	div = 2;
	if (nb == 2)
		return (1);
	if (nb <= 1 || !(nb % 2))
		return (0);
	while (div <= (nb / div))
	{
		if (!(nb % div))
			return (0);
		div++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	if (nb <= 1)
		return (2);
	while (!ft_is_prime(nb))
		nb++;
	return (nb);
}
