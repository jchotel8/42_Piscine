/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 13:30:14 by llaurent          #+#    #+#             */
/*   Updated: 2019/08/18 16:37:14 by llaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rush02.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	char	*output;
	char	*dictonnary;
	char	*number;

	if (ac == 1)
	{
		ft_putstr(ARGUMENT_ERROR);
		return (MAIN_ERROR);
	}
	if (ac == 3)
	{
		if ((dictonnary = get_dico(av[1])) == NULL)
			return (MAIN_ERROR);
		number = av[2];
	}
	else if (ac == 2)
	{
		if ((dictonnary = get_dico(DICT_NAME)) == NULL)
			return (MAIN_ERROR);
		number = av[1];
	}
	if (!is_valid(number))
	{
		ft_putstr(ARGUMENT_ERROR);
		return (MAIN_ERROR);
	}
	if (!dico_is_valid(dictonnary, "sample.dict"))
	{
		ft_putstr(DICT_ERROR);
		return (MAIN_ERROR);
	}
	// NE PAS OUBLIE DE RENVOYER "ARGUMENT_ERROR" SI LE DICTIONNAIRE NE PERMET
	// PAS    DE     CONVERTIR     L'ENTIER    EN    CHAINE    DE    CARACTERE
	ft_rush02(number, dictonnary);
	ft_putstr("\n");
	return (MAIN_SUCCESS);
}
