/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchotel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 03:25:19 by jchotel           #+#    #+#             */
/*   Updated: 2019/08/04 22:31:01 by vshiraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int		rush(int x, int y);

int		ft_atoi(char *str)
{
	int i;
	int sign;
	int result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == '\f' || str[i] == '\n'
			|| str[i] == '\r' || str[i] == '\t' || str[i] == '\v' || )
		str[i]++;
    
	if (str[i] == '-')
		sign = -1;
	while (str[i++] >= '0' && str[i - 1] <= '9')
		result = result * 10 + str[i - 1] - 48;
	return (result * sign);
}

int		main(int argc, char **argv)
{
	int x;
	int y;

	x = ft_atoi(argv[1]);
	y = ft_atoi(argv[2]);
	rush(x, y);
	return (0);
}
