/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchotel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 11:46:38 by jchotel           #+#    #+#             */
/*   Updated: 2019/08/12 19:01:55 by jchotel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_hexa(char str)
{
	int		div;
	int		mod;
	char	*baseh;

	baseh = "0123456789abcdef";
	div = str / 16;
	mod = str % 16;
	write(1, &baseh[div], 1);
	write(1, &baseh[mod], 1);
}

void	ft_putstr_non_printable(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 32 || str[i] >= 126)
		{
			write(1, "\\", 1);
			ft_hexa(str[i]);
		}
		else
			write(1, &str[i], 1);
		i++;
	}
}
