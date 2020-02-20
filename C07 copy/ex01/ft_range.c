/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchotel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 07:40:01 by jchotel           #+#    #+#             */
/*   Updated: 2019/08/18 08:13:27 by jchotel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int *ft_range(int min, int max)
{
	int i;
	int *res;

	i = 0;
	if (min >= max)
		return (0);
	if (!(res = (int *)malloc(sizeof(int)*(max - min))))
		return (0);
	while (res[i])
	{
		res[i] = min;
		i++;
		min++;
	}
	return(res);
}

int main (int argc, char **argv)
{
	int * rep;
	int taille;
	int i;

	i = 0;
	taille = atoi(argv[2]) - atoi(argv[1]);
	rep = ft_range(atoi(argv[1]), atoi(argv[2]));
	while (i < taille - 1)
	{
		printf("%d", rep);
		i++;
	}
	return (0);
}
