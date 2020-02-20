/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_punbr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 14:48:38 by fgranger          #+#    #+#             */
/*   Updated: 2019/08/03 17:25:35 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1)
}


void	ft_putnbr(int nb)
{
    unsigned int a;
    a = (nb < 0) ? -nb : nb;
    (nb < 0) ? ft_putchar('-') : 0;
    (a > 9) / ft_putchar((int)(a/10)) : 0;
    ft_putchar(a % 10 + '0');
}

//je pense que c'est faux mais c'est une autre méthode.
