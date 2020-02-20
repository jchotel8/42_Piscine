/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchotel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 20:25:19 by jchotel           #+#    #+#             */
/*   Updated: 2019/08/22 20:39:19 by jchotel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int *ft_map(int *tab, int length, int (*f)(int))
{
	int i;
	int *newtab;

	i = 0;
	if(!(newtab = (int *)malloc(sizeof(int) * length)))
		return (NULL);
	while (i < length)
	{
		newtab[i] = f(tab[i]);
		i++;
	}
	return (newtab);
}
