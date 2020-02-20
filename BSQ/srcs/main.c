/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchotel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 10:33:30 by jchotel           #+#    #+#             */
/*   Updated: 2019/08/21 23:37:19 by jchotel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

void	err(int index, int ac, char *err_msg)
{
	int	index2;

	index2 = 0;
	while (err_msg[index2])
	{
		write(ERROR_OUTPUT, &err_msg[index2], 1);
		index2++;
	}
	if (ac > 2 && index != ac - 1)
		write(ERROR_OUTPUT, "\n", 1);
}

char	*write_stdin(void)
{
	int		fd;
	char	buffer[BUFF_SIZE + 1];
	char	*content;
	int		index;
	int		r;

	fd = 0;
	if (!(content = (char *)malloc(sizeof(char))))
		return (NULL);
	index = 0;
	content[0] = '\0';
	while ((r = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[r] = 0;
		content = ft_strjoin(content, buffer);
	}
	if (close(fd) == -1)
		return (NULL);
	return (content);
}

void	fill_and_display(int index, int ac, t_map *map)
{
	fill_map(map);
	display_map(*map);
	if (index != ac - 1 && ac > 2)
		ft_putstr("\n");
}

int		send_to_algo(char *content, int ac, t_map *map)
{
	int	index;

	index = 0;
	if (get_map(-1, "", map, content) != SUCCESS)
	{
		err(index, ac, MSG_ERR_CANNOT_READ_MAP);
		return (ERR_CANNOT_READ_MAP);
	}
	if (!contains_only(map->tab, map->data.c_void, map->data.c_obs))
	{
		err(index, ac, MSG_ERR_CANNOT_READ_MAP);
		return (ERR_CANNOT_READ_MAP);
	}
	fill_and_display(index, ac, map);
	return (SUCCESS);
}

int		main(int ac, char **av)
{
	t_map	map;
	int		index;

	index = 0;
	if (ac < 2)
		if (send_to_algo(write_stdin(), ac, &map) != SUCCESS)
			return (ERR_CANNOT_READ_MAP);
	while (++index < ac)
	{
		if (get_map(-1, av[index], &map, "\0") != SUCCESS)
		{
			err(index, ac, MSG_ERR_CANNOT_READ_MAP);
			continue;
		}
		if (!contains_only(map.tab, map.data.c_void, map.data.c_obs))
		{
			err(index, ac, MSG_ERR_CANNOT_READ_MAP);
			continue;
		}
		fill_and_display(index, ac, &map);
	}
	return (SUCCESS);
}
