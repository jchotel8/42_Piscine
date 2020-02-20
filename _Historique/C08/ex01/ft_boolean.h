/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boolean.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchotel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 17:43:35 by jchotel           #+#    #+#             */
/*   Updated: 2019/08/15 18:53:04 by jchotel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FT_BOOLEAN_H
# define FT_BOOLEAN_H

# include <unistd.h>

typedef int	t_bool;

# define TRUE 1
# define FALSE 0
# define EVEN(x) ((x % 2) == 0 ?  TRUE : FALSE)
# define SUCCESS 0

# define EVEN_MSG "I have an even number of arguments."
# define ODD_MSG "I have an odd number of arguments."

t_bool ft_is_even(int nbr);
void ft_putstr(char *str);

#endif
