/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchotel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 12:04:00 by jchotel           #+#    #+#             */
/*   Updated: 2019/08/21 23:37:48 by jchotel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

char	*get_content(char *file_name)
{
	int		fd;
	char	buffer[BUFF_SIZE + 1];
	char	*content;
	int		index;
	int		r;

	if (!(content = (char *)malloc(sizeof(char))))
		return (NULL);
	if ((fd = open(file_name, O_RDONLY)) == -1)
		return (NULL);
	index = 0;
	content[0] = '\0';
	while ((r = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[r] = 0;
		content = ft_strjoin(content, buffer);
	}
	if (close(fd) == -1 || ft_strlen(content) < 1)
		return (NULL);
	return (content);
}

int		get_number_of_line(char *str, int *index)
{
	int	result;

	result = 0;
	if (!str)
		return (0);
	while ((str[*index] >= 8 && str[*index] <= 13) || str[*index] == ' ')
		*index += 1;
	while (str[*index] >= '0' && str[*index] <= '9')
	{
		result = result * 10 + str[*index] - '0';
		*index += 1;
	}
	return (result);
}

void	ft_free(char **splitted, char *content)
{
	free(splitted);
	free(content);
}

t_data	get_data(char *map_content, int *index_get_map)
{
	t_data	data;
	char	**splitted;
	char	*first_line;
	int		index;

	index = 0;
	*index_get_map = 1;
	splitted = ft_split(map_content, "\n");
	first_line = splitted[0];
	data.line_num = get_number_of_line(first_line, &index);
	data.c_void = map_content[index++];
	data.c_obs = map_content[index++];
	data.c_full = map_content[index++];
	free(splitted);
	return (data);
}

int		get_map(int number, char *file_name, t_map *m, char *std)
{
	char	*content;
	char	**splitted;
	int		index;

	if (!(content = (std[0] == '\0' ? get_content(file_name) : std)) || !m)
		return (ERR_CANNOT_READ_MAP);
	m->data = get_data(content, &index);
	if (m->data.line_num == 0)
		return (ERR_CANNOT_READ_MAP);
	splitted = ft_split(content, "\n");
	if (!(m->tab = (char **)malloc(sizeof(char *) * (m->data.line_num + 2))))
		return (ERR_CANNOT_READ_MAP);
	while (splitted[index])
	{
		if (number != ft_strlen(splitted[index]) && number != -1)
			return (ERR_CANNOT_READ_MAP);
		number = ft_strlen(splitted[index]);
		m->tab[index - 1] = ft_strdup(splitted[index]);
		index++;
	}
	if (m->data.line_num != index - 1)
		return (ERR_CANNOT_READ_MAP);
	m->tab[index - 1] = NULL;
	ft_free(splitted, content);
	return (SUCCESS);
}
