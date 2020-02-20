/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 13:32:33 by llaurent          #+#    #+#             */
/*   Updated: 2019/08/21 16:02:00 by jchotel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH02_H
# define RUSH02_H
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# define DICT_NAME "numbers.dict"
# define DICT_ERROR "Dict error\n"
# define ARGUMENT_ERROR "Error\n"
# define MAIN_ERROR 1
# define MAIN_SUCCESS 0
# define BONUS 1

void	ft_putstr(char *str);
int		ft_strcmp(char *s1, char *s2);
char	**ft_split(char *str, char *charset);
char	*get_dico(char *dictonnary);
int		ft_strlen(char *str);
char	*get_value_by_number(char *dictonnary, char *getter);
int		is_valid(char *number);
char	*ft_itoa(int nbr);
char	*ft_strstr(char *str, char *to_find);
int		dico_is_valid(char *dict, char *sample);
int		*ft_numbers(char *str, char *dict);
#endif
