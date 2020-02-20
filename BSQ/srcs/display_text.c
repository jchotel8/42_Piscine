/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_text.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 12:10:19 by fgranger          #+#    #+#             */
/*   Updated: 2019/08/21 23:31:20 by jchotel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

void	ft_display_text(int output, char *message)
{
	int	index;

	index = 0;
	while (message[index])
	{
		write(output, &message[index], 1);
		index++;
	}
}
