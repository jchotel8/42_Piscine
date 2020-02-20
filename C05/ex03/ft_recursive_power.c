/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchotel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 11:42:41 by jchotel           #+#    #+#             */
/*   Updated: 2019/08/18 03:53:02 by jchotel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	if (power == 1)
		return (nb);
	if ((nb == 0 && power != 0) || power < 0)
		return (0);
	if (power == 0 || (power == 0 && nb == 0))
		return (1);
	return (nb * ft_recursive_power(nb, power - 1));
}
