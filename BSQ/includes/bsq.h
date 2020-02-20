/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frganger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 11:45:58 by fgranger          #+#    #+#             */
/*   Updated: 2019/08/21 23:29:56 by jchotel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# define ERROR_OUTPUT 2
# define STANDARD_OUTPUT 1
# define STANDARD_INPUT 0
# define DEFAULT_MAP_NAME "example_map"
# define ERR_ARGUMENTS 1
# define BUFF_SIZE 1024 * 64
# define MSG_ERR_ARGUMENTS "Error\n"
# define ERR_CANNOT_READ_MAP 2
# define MSG_ERR_CANNOT_READ_MAP "map error\n"
# define SUCCESS 0

typedef struct		s_data
{
	char	c_void;
	char	c_full;
	char	c_obs;
	int		line_num;
	int		ln;
}					t_data;
typedef struct		s_map
{
	t_data	data;
	char	**tab;
}					t_map;
void				ft_display_text(int output, char *message);
int					get_map(int number, char *file_name, t_map *map, char *std);
int					ft_atoi(char *str);
char				**ft_split(char *str, char *charset);
char				*ft_strdup(char *src);
int					display_map(t_map map);
void				ft_putstr(char *str);
int					ft_strlen(char *str);
int					fill_map(t_map *map);
int					contains_only(char **tab, char c_1, char c_2);
char				*ft_strjoin(char *str1, char *str2);
#endif
