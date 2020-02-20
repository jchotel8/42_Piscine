/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchotel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 17:29:53 by jchotel           #+#    #+#             */
/*   Updated: 2019/08/13 11:12:53 by jchotel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned	int i;
	unsigned	int index;

	i = 0;
	index = 0;
	while (src[index])
	{
		index++;
	}
	if (size > 1)
	{
		while (i < size - 1 && src[i] != '\0')
		{
			dest[i] = src[i];
			i++;
		}
	}
	if (size >= 1)
		dest[i] = '\0';
	return (index);
}
