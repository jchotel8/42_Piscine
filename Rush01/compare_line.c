/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoechli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 19:39:17 by gkoechli          #+#    #+#             */
/*   Updated: 2019/08/11 19:45:52 by gkoechli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_compare_line_rl(int i, int j, int tab[4][4])
{
	int x;
	int count;
	int max;
	int tabArg[16] = {3,2,1,3,2,3,2,1,3,2,1,3,2,3,2,1};

	count = 1;
	max = tab[3][j];
	x = 2;
	while (x >= 0)
	{
		if (max < tab[x][j])
		{
			count++;
			max = tab[x][j];
		}
		x--;
	}
	if (tabArg[j + 4] != count)
		return (0);
	return (1);
}

int		ft_compare_line_lr(int i, int j, int tab[4][4])
{
	int count;
	int max;
	int x;
	int tabArg[16] = {3,2,1,3,2,3,2,1,3,2,1,3,2,3,2,1};

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
	if (tabArg[j] != count)
		return (0);
	return (1);
}

int		ft_compare_line(int i, int j, int tab[4][4])
{
	ft_compare_line_rl(int i, int j, int tab[4][4]);
	ft_compare_line_lr(int i, int j, int tab[4][4]);

}
