/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 14:52:45 by asimon            #+#    #+#             */
/*   Updated: 2019/08/10 15:49:05 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include "rush01_lib.h"

int		ft_check_argv_error(char *str)
{
	int		i;
	int		*tab;

	i = 0;
	if (!(str[0] >= 48 && str[0] <= 5))
		ft_error();
	while (str[i])
	{
		if (i % 2 == 0 && !(str[i] <= 57 && str[i] >= 48))
		{
			ft_error();
			return (0);
		}
		if (i % 2 != 0 && str[i] != ' ')
		{
			ft_error();
			return (0);
		}
	}
	return (1);
}

int			ft_error()
{
	int		i;
	char	*erreur;

	erreur = "Error\n";
	while (erreur[i])
	{
		write(1, &erreur[i], 1);
		i++;
	}
	return (0);
}
