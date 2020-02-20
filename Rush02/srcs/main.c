/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 13:30:14 by llaurent          #+#    #+#             */
/*   Updated: 2019/08/18 23:26:05 by llaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rush02.h"
#include <stdio.h>

int	verif(int ac, char **av, char **dictonnary, char **number)
{
	if (ac != 3 && ac != 2)
	{
		ft_putstr(ARGUMENT_ERROR);
		return (0);
	}
	if (ac == 3 && !(*dictonnary = get_dico(av[1])))
		return (0);
	*number = av[2];
	if (ac == 2)
	{
		if ((*dictonnary = get_dico(DICT_NAME)) == NULL)
			return (MAIN_ERROR);
		*number = av[1];
	}
	if (ft_strlen(*number) > 12)
	{
		ft_putstr("You have reached the max int value : 999999999999\n");
		return (0);
	}
	return (1);
}

int	main(int ac, char **av)
{
	char	*dictonnary;
	char	*number;

	number = NULL;
	dictonnary = NULL;
	if (!verif(ac, av, &dictonnary, &number))
		return (0);
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
	ft_numbers(number, dictonnary);
	ft_putstr("\n");
	return (MAIN_SUCCESS);
}
