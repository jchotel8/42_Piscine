/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 16:23:33 by llaurent          #+#    #+#             */
/*   Updated: 2019/08/17 18:45:20 by llaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_valid(char *number)
{
	int	index;

	index = 0;
	while (number[index])
	{
		if (!(number[index] >= '0' && number[index] <= '9'))
			return (0);
		index++;
	}
	return (1);
}
