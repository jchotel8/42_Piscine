/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare_case.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoechli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 18:53:57 by gkoechli          #+#    #+#             */
/*   Updated: 2019/08/11 19:52:36 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01_lib.h"

int		ft_compare_case_xx(int i, int j, int tab[4][4])
{
	int x;
	int y;
//	int tabArg[16] = {3,2,1,3,2,3,2,1,3,2,1,3,2,3,2,1};

	x = 0;
	y = 0;
	while (x < 4)
	{
		if (tab[x][j] == tab[i][j] && i != x)
			return (0);
		x++;
	}
	while (y < 4)
	{
		if (tab[i][y] == tab[i][j] && y != j)
			return (0);
		y++;
	}
	return (1);
}

int		ft_compare_case_lr(int i, int j, int tab[4][4])
{
	int x;
	int	count;
	int max;
//	int tabArg[16] = {3,2,1,3,2,3,2,1,3,2,1,3,2,3,2,1};

	count = 1;
	max = tab[0][j];
	x = 1;
	while (x < 4)
	{
		if (max < tab[x][j])
		{
			count++;
			max = tab[x][j];
		}
		x++;
	}
	if (tabArg[j] < count)
		return (0);
	return (1);
}

int		ft_compare_case_ud(int i, int j, int tab[4][4])
{
	int y;
	int count;
	int max;
//	int tabArg[16] = {3,2,1,3,2,3,2,1,3,2,1,3,2,3,2,1};

	count = 1;
	max = tab[i][0];
	y = 1;
	while (y < 4)
	{
		if (max < tab[i][y])
		{
			count++;
			max = tab[i][y];
		}
		y++;
	}
	if (tabArg[i + 8] < count)
		return (0);
	return (1);
}

int ft_compare_case(int i, int j, int tab[4][4])
{
	//int tabArg[16] = {3,2,1,3,2,3,2,1,3,2,1,3,2,3,2,1};

	if ((ft_compare_case_xx( i,  j,  tab) == 1) &&
		(ft_compare_case_lr( i,  j,  tab) == 1) &&
		(ft_compare_case_ud( i,  j,  tab) == 1))
		return (1);
	else
		return (0);
	
}
