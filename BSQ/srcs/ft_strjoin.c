/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchotel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 19:10:23 by jchotel           #+#    #+#             */
/*   Updated: 2019/08/21 23:35:32 by jchotel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/bsq.h"

char	*ft_strjoin(char *str1, char *str2)
{
	char	*res;
	int		len2;
	int		i;

	len2 = ft_strlen(str2);
	if (!(res = (char *)malloc(sizeof(char) * (ft_strlen(str1) + len2 + 1))))
		return (NULL);
	i = 0;
	while (i < ft_strlen(str1))
	{
		res[i] = str1[i];
		i++;
	}
	i = 0;
	while (i < len2)
	{
		res[ft_strlen(str1) + i] = str2[i];
		i++;
	}
	res[ft_strlen(str1) + i] = '\0';
	free(str1);
	return (res);
}
