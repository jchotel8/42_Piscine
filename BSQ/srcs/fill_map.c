/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 14:19:21 by fgranger          #+#    #+#             */
/*   Updated: 2019/08/21 23:31:54 by jchotel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

int		check_posi(int *tab, char **carte, char c_obs)
{
	int i;
	int j;

	i = tab[2];
	j = tab[1];
	while (j < tab[1] + tab[0])
	{
		while (i < tab[2] + tab[0])
		{
			if (carte[j][i] == c_obs)
				return (0);
			i++;
		}
		i = tab[2];
		j++;
	}
	return (1);
}

void	set_value(int *tab, int pos, int size, int n)
{
	if (n == 0)
		tab[n] = size;
	else
		tab[n] = pos;
}

int		*inc(int n, int *tab, char **carte, t_map *map)
{
	int			size;
	int			pos;
	static int	flag;

	flag = 0;
	size = (map->data.ln <= map->data.line_num ?
			map->data.ln : map->data.line_num);
	pos = 0;
	while (size >= 0 && pos <= (map->data.line_num >= map->data.ln ?
				map->data.line_num : map->data.ln) && flag == 0)
	{
		set_value(tab, pos, size, n);
		if (n < 2)
			inc(n + 1, tab, carte, map);
		else if (tab[1] + tab[0] <= map->data.line_num && tab[2] + tab[0] <=
				map->data.ln && check_posi(tab, carte, map->data.c_obs))
		{
			flag = 1;
			return (0);
		}
		if (n == 0)
			size--;
		pos++;
	}
	return (tab);
}

int		*bsq(t_map *map, int line_len)
{
	int	*tab;
	int	*ints;

	if ((tab = (int *)malloc(sizeof(int) * 3)) == NULL)
		return (0);
	if ((ints = (int *)malloc(sizeof(int) * 2)) == NULL)
		return (0);
	map->data.ln = line_len;
	return (inc(0, tab, map->tab, map));
}

int		fill_map(t_map *map)
{
	int		line_len;
	int		*tab;
	int		x;
	int		y;
	int		size;

	line_len = ft_strlen(map->tab[0]);
	if (!(tab = bsq(map, line_len)))
		return (0);
	size = tab[0];
	x = tab[2];
	y = tab[1];
	while (y < tab[1] + (size))
	{
		x = tab[2];
		while (x < tab[2] + (size))
		{
			map->tab[y][x] = map->data.c_full;
			x++;
		}
		y++;
	}
	return (SUCCESS);
}
