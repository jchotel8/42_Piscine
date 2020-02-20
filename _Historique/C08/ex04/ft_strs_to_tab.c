/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchotel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 19:13:55 by jchotel           #+#    #+#             */
/*   Updated: 2019/08/15 19:17:01 by jchotel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"

int        ft_strlen(char *str)
{
    int i;
    
    i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return (i);
}

char    *ft_strdup(char *src)
{
    char    *res;
    int        i;
    
    i = 0;
    while (src[i] != '\0')
        i++;
    if (!(res = (char *)malloc(sizeof(char) * i + 1)))
        return (0);
    i = 0;
    while (src[i] != '\0')
    {
        res[i] = src[i];
        i++;
    }
    res[i] = '\0';
    return (res);
}

t_stock_str *ft_strs_to_tab(int ac, char **av)
{
    t_stock_str *tab;
    int i;
    
    i = 0;
    if(!(tab = (t_stock_str *)malloc(sizeof(t_stock_str)(ac + 1))))
        return (0);
    while (i < ac)
    {
        tab[i].size = strlen(av[i]);
        tab[i].str = av[i];
        tab[i].copy = ft_strdup(av[i]);
        i++;
    }
    tab[i].str = 0;
    return (*tab);
}


