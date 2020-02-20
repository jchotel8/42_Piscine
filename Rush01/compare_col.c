/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare_col.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoechli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 19:10:57 by gkoechli          #+#    #+#             */
/*   Updated: 2019/08/11 19:30:18 by gkoechli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int		ft_compare_col_du(int i, int j, int tab[4][4])
{
	int y;
	int count;
	int max;
	int tabArg[16] = {3,2,1,3,2,3,2,1,3,2,1,3,2,3,2,1};

	count = 1;
	max = tab[i][3];
	y = 2;
	while (y >= 0)
	{
		if (max < tab[i][y])
		{
			count++;
			max = tab[i][y];
		}
		y--;
	}
	if (tabArg[i + 12] != count)
		return (0);
	return (1);
}

int		ft_compare_col_ud(int i, int j, int tab[4][4])
{
	int y;
	int count;
	int max;
	int tabArg[16] = {3,2,1,3,2,3,2,1,3,2,1,3,2,3,2,1};

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
	if (tabArg[i + 8] != count)
		return (0);
	return(1);
}

int		ft_compare_col(int i, int j, int tab[4][4])
{
	int tabArg[16] = {3,2,1,3,2,3,2,1,3,2,1,3,2,3,2,1};

	ft_compare_col_du(int i, int j, int tab[4][4]);
	ft_compare_col_ud(int i, int j; int tab[4][4]);	
}
