/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchotel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 14:04:06 by jchotel           #+#    #+#             */
/*   Updated: 2019/08/06 14:06:19 by jchotel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	recursive_combn(int n, int tab[], int valmin, int indice)
{
	int j;
	int val;
	int a;

	if (indice == n)
	{
		j = 0;
		while (j < n)
		{
			a = tab[j] + 47;
			write(1, &a, 1);
			j++;
		}
		if (tab[0] <= 10 - n)
			write(1, ", ", 2);
	}
	val = valmin;
	while (val <= 9)
	{
		tab[indice] = val + 1;
		recursive_combn(n, tab, val + 1, indice + 1);
		val++;
	}
}

void	ft_print_combn(int n)
{
	int tab[n];

	if (n > 0 && n < 10)
	{
		recursive_combn(n, tab, 0, 0);
	}
}
