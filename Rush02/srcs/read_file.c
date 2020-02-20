/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 13:48:05 by llaurent          #+#    #+#             */
/*   Updated: 2019/08/18 23:23:47 by llaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rush02.h"
#include <stdio.h>

int		f_size(char *file_name)
{
	int		index;
	char	buffer;
	int		fd;

	if ((fd = open(file_name, O_RDONLY)) == -1)
	{
		ft_putstr(DICT_ERROR);
		return (0);
	}
	index = 0;
	while (read(fd, &buffer, 1) != 0)
	{
		index++;
	}
	close(fd);
	return (index);
}

void	fill_dico(char *output, int fd)
{
	int		index;
	char	buffer;

	index = 0;
	while (read(fd, &buffer, 1) != 0)
	{
		output[index] = buffer;
		index++;
	}
}

char	*get_dico(char *dictonnary)
{
	int		fd;
	char	*output;
	int		len;

	len = f_size(dictonnary);
	if (len == 0)
		return (0);
	if ((output = (char *)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	output[len] = '\0';
	if ((fd = open(dictonnary, O_RDONLY)) == -1)
	{
		ft_putstr(DICT_ERROR);
		return (0);
	}
	fill_dico(output, fd);
	if (close(fd) == -1)
		return (NULL);
	return (output);
}

char	*remove_spaces(char *str)
{
	int		index;
	char	*output;
	int		index2;

	index = 0;
	index2 = 0;
	while (str[index] == ' ' || str[index] == '\t')
		index++;
	output = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	while (str[index])
	{
		if (str[index] >= 'a' && str[index] <= 'z')
			output[index2] = str[index];
		index++;
		index2++;
	}
	output[index2] = 0;
	return (output);
}

char	*get_value_by_number(char *dictonnary, char *getter)
{
	char	**splitted;
	char	*key;
	char	*value;
	int		index;

	index = 0;
	splitted = ft_split(dictonnary, "\n");
	while (splitted[index])
	{
		key = ft_split(splitted[index], ":")[0];
		value = ft_split(splitted[index], ":")[1];
		if (ft_strcmp(key, getter) == 0)
		{
			free(key);
			free(splitted);
			return (remove_spaces(value));
		}
		index++;
	}
	return (NULL);
}
