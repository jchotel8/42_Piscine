/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchotel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 20:55:18 by jchotel           #+#    #+#             */
/*   Updated: 2019/08/21 23:34:56 by jchotel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/bsq.h"

char	*ft_strdup(char *src)
{
	int		len;
	char	*str;
	int		index;

	index = 0;
	len = ft_strlen(src);
	if ((str = (char *)malloc(sizeof(*src) * (len + 1))) == NULL)
		return (NULL);
	while (index < len)
	{
		str[index] = src[index];
		index++;
	}
	str[index] = '\0';
	return (str);
}
