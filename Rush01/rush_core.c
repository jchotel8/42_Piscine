/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush_core.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoechli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 19:52:48 by gkoechli          #+#    #+#             */
/*   Updated: 2019/08/11 20:22:55 by gkoechli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_backtrack_one(int i, int j, tabVide[i][j])
{
	tabVide[i][j]++;
	while (ft_compare_case(i, j, tabVide) == 0 && tabVide[i][j] < 5)
	{
		tabVide[i][j]++;
	}
	if (ft_compare_case(i, j, tabVide) == 0 || tabVide[i][j] > 4)
	{
		tabVide[i][j] = 0;
		if (j == 0) //&& i != 0)
		{
			i--;
			j = 2;
		}
		else //if (i != 0 && j != 0)
			j -= 2;
	}
	else
		ft_backtrack_two(i, j, tabVide[i][j]);
}

void	ft_backtrack_two(int i, int j, tabVide[i][j])
{
	if ((j == 3 && ft_compare_ligne(i, j, tabVide) == 0) 
	|| (i == 3 && ft_compare_colonne(i, j, tabVide) == 0))
	{
		tabVide[i][j] = 0;
		if (j == 0) //&& i != 0)
		{
			i--;
			j = 2;
		}
		else //if (i != 0 && j != 0)
			j -= 2;
	}
}

void	rush_core(int i, int j, tabVide[i][j])
{
	int tabVide[4][4] = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
	
	i = 0;
	j = 0;
	while (i < 4)
	{
		while (j < 4)
		{
			ft_backtrack_one(i, j, tabVide[i][j]);
			j++;
		}
		i++;
		j = 0;
	}
}
