/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock_str.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchotel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 19:13:55 by jchotel           #+#    #+#             */
/*   Updated: 2019/08/15 19:17:01 by jchotel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STOCK_STR_H
#define FT_STOKC_STR_H

typedef struct s_stock_str
{
	int size;
	char *str;
    char *copy;
}              t_stock_str;

struct s_stock_str *ft_strs_to_tab(int ac, char **av);

#endif
