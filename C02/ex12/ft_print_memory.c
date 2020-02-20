/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchotel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 21:18:06 by jchotel           #+#    #+#             */
/*   Updated: 2019/08/12 19:25:48 by jchotel          ###   ########.fr       */
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

void	putchar(char c)
{
	write(1, &c, 1);
}

void	ft_hexalong(unsigned long int nbr)
{
	char	*baseh;
	int		mod;

	baseh = "0123456789abcdef";
	if (nbr > 16)
	{
		ft_hexalong(nbr / 16);
		mod = nbr % 16;
		putchar(baseh[mod]);
	}
	else
		putchar(baseh[nbr]);
}

void	ft_print_memory(void *addr, unsigned int size)
{
	int					i;
	int					j;
	int					k;
	char				*chaine = (char *)addr;
	unsigned long int	addresse;

	i = 0;
	j = 1;
	k = 0;
	size = 0;
	while (chaine[i] != '\0')
	{
		write (1, "00000000", 8);
		addresse = (unsigned long int)(chaine + i);
		ft_hexalong(addresse);
		write (1, ": ", 2);
		while (k / 16 < j)
		{
			if (chaine[k] > 1 )
				ft_hexa(chaine[k]);
			else
				write (1, "  ", 2);
			if ((k + 1) % 2 == 0)
				write (1, " ", 1);
			k++;
		}
		while (i / 16 < j && chaine[i] != '\0')
		{
			if (chaine[i] >= 32 && chaine[i] < 127)
				write (1, &chaine[i], 1);
			else
				write (1, ".", 1);
			i++;
		}
		write (1, "\n", 1);
		j++;
	}
}


int main (void)
{
	char *str = "Bonjour les am..print_memory....lol.lol. ";
	ft_print_memory(str, 20);
	return (0);
}
