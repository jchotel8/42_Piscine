/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchotel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 03:25:19 by jchotel           #+#    #+#             */
/*   Updated: 2019/08/04 23:39:10 by vshiraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	condition(int i, int j, int x, int y)
{
	if (i == 0 && j == 0)
		write(1, "/", 1);
	else if (j == x - 1 && i == 0)
		write(1, "\\", 1);
	else if (i == y - 1 && j == 0)
		write(1, "\\", 1);
	else if (i == y - 1 && j == x - 1)
		write(1, "/", 1);
	else if (i == 0 || i == y - 1 || j == 0 || j == x - 1)
		write(1, "*", 1);
	else
		write(1, " ", 1);
}

void	rush(int x, int y)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < y && j < x)
	{
		while (j < x)
		{
			condition(i, j, x, y);
			j++;
		}
		write(1, "\n", 1);
		j = 0;
		i++;
	}
}
