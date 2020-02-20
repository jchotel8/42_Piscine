/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchotel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 22:54:22 by jchotel           #+#    #+#             */
/*   Updated: 2019/08/18 04:07:30 by jchotel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		val_abs(int val)
{
	if (val < 0)
		val *= -1;
	return (val);
}

int		check_posi(int *tab, int n)
{
	int i;
	int j;

	i = 0;
	j = 1;
	while (j < n)
	{
		while (i < j)
		{
			if (tab[i] == tab[j])
				return (0);
			if (val_abs(tab[i] - tab[j]) == val_abs(i - j))
				return (0);
			i++;
		}
		i = 0;
		j++;
	}
	return (1);
}

void	print_table(int *tab)
{
	int i;
	int val;

	i = 0;
	while (i < 10)
	{
		val = tab[i] + 48;
		write(1, &val, 1);
		i++;
	}
}

int		incrementation(int n, int *tab)
{
	int			val;
	static int	test = 0;

	val = 0;
	while (val < 10)
	{
		tab[n] = val;
		if (n < 9 && check_posi(tab, n))
			incrementation(n + 1, tab);
		else if (check_posi(tab, 10))
		{
			print_table(tab);
			write(1, "\n", 1);
			test++;
		}
		val++;
	}
	return (test);
}

int		ft_ten_queens_puzzle(void)
{
	int tab[10];

	return (incrementation(0, tab));
}

int main(void)
{
    ft_ten_queens_puzzle();
    return(0);
}
