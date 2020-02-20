/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchotel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 03:25:19 by jchotel           #+#    #+#             */
/*   Updated: 2019/08/04 23:37:08 by vshiraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	rush(int jmax, int imax)
{
	int		i;
	int		j;
	char	tab[imax][jmax];

	i = -1;
	j = 0;
	while (i++ < imax - 1 && j < jmax)
	{
		while (j < jmax)
		{
			tab[i][j] = ' ';
			if (i == 0 || i == imax - 1)
				tab[i][j] = '-';
			if (j == 0 || j == jmax - 1)
				tab[i][j] = '|';
			if ((i == 0 && j == 0) || (i == 0 && j == jmax - 1))
				tab[i][j] = 'o';
			if ((j == 0 && i == imax - 1) || (j == jmax - 1 && i == imax - 1))
				tab[i][j] = 'o';
			write(1, &tab[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		j = 0;
	}
}
