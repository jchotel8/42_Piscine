/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchotel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 13:44:59 by jchotel           #+#    #+#             */
/*   Updated: 2019/08/06 23:18:23 by jchotel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_ultimate_div_mod(int *a, int *b)
{
	int tmp;

	if (*b != 0)
	{
		tmp = *a / *b;
		*b = *a % *b;
		*a = tmp;
	}
}
