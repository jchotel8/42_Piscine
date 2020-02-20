/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush-02.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchotel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 12:28:00 by jchotel           #+#    #+#             */
/*   Updated: 2019/08/17 12:50:02 by jchotel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int         ft_iterative_power(int nb, int power)
{
    int     result;
    
    result = 1;
    if ((nb == 0 && power !=0) || power < 0)
        return (0);
    if ((power == 0) || (( nb < 0) && (power == 0)))
        return (1);
    else
    {
        while (power > 0)
        {
            result =  nb * result;
            power--;
        }
        return (result);
    }
}


void ft_rush02(char *nbr)
{
    int i;
    int taille;
    int key;
    
    taille = 0;
    key = 10;
    
    //CALCULER LA LONGEUR TOTAL DU PARAMETRE
    while (nbr[taille])
    {
        taille++;
    }
    i = 0;

    //CALCULER LE RANG POUR CHAQUE CHIFFRE
    while (nbr[i])
    {
        if ((taille - i - 1)%3 == 2 && nbr[i] != '0')       //ICI
        {//affiche la valeur des unités
            key = nbr[i] - 48;
            printf("3 the key is : %d for the number %c \n", key, nbr[i]);
        }
        //calcul le rang
        key = ft_iterative_power(10, (taille - i - 1)%3);
        if (((taille - i - 1)%3 == 1 && nbr[i] != '1') || (taille - i - 1)%3 == 0)
        {//affiche les dizaines et les unités
            key = key * (nbr[i] - 48);
        }
        if ((taille - i - 1)%3 == 1 && nbr[i] == '1')
        {//affiche de 10 a 19
            i++;
            key = key + (nbr[i] - 48);
        }
        if (nbr[i] != '0' || taille == 1)                   //ICI
            printf("2 the key is : %d for the number %c \n", key, nbr[i]);
        if((taille - i - 1)%3 == 0 && (taille - i -1) != 0)
        {
            key = ft_iterative_power(10, (taille - i - 1));
            printf("1 the key is : %d for the number %c \n", key, nbr[i]);
            write (1, ", ", 2);
        }
        i++;
   }
}

int main(int argc, char ** argv)
{
	ft_rush02(argv[1]);
	return (0);
}
