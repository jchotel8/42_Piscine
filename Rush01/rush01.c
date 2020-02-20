#include <stdlib.h>
#include <stdio.h>

int ft_compare_case(int i, int j, int tab[4][4])
{
    int x;
    int y;
    
    x = 0;
    y = 0;
    //parcourir la ligne et verifier les doublons
    while (x < 4)
    {
        if (tab[x][j] == tab[i][j] && i != x)
            return (0);
        x++;
    }
    //parcourir la colonne et verifier les doublons
    while (y < 4)
    {
        if (tab[i][y] == tab[i][j] && y != j)
            return (0);
        y++;
    }
    return (1);
}




int ft_compare_ligne(int i, int j, int tab[4][4]) //int tabArg[16])
{
    int x;
    int y;
    int count;
    int max;
    int tabArg[16] = {3,2,1,3,2,3,2,1,3,2,1,3,2,3,2,1};
    
    count = 1;
    max = tab[i][3];
    y = 2;
    while (y >= 0)
    {
        if (max < tab[i][y])
        {
            count++;
            max = tab[i][y];
        }
        y--;
    }
    if (tabArg[i + 12] != count)
        return (0);
    //printf("downup : %d\n", count);
    
    count = 1;
    max = tab[i][0];
    y = 1;
    while (y < 4)
    {
        if (max < tab[i][y])
        {
            count++;
            max = tab[i][y];
        }
        y++;
    }
    if (tabArg[i + 8] != count)
        return (0);
    //printf("updown: %d\n", count);
    
    return (1);
}



int ft_compare_colonne(int i, int j, int tab[4][4])//, int tabArg[16])
{
    int x;
    int y;
    int count;
    int max;
    int tabArg[16] = {3,2,1,3,2,3,2,1,3,2,1,3,2,3,2,1};
    
    count = 1;
    max = tab[3][j];
    x = 2;
    while (x >= 0)
    {
        if (max < tab[x][j])
        {
            count++;
            max = tab[x][j];
        }
        x--;
    }
    if (tabArg[j + 4] != count)
        return (0);
    //printf("rightleft : %d\n", count);
    
    
    count = 1;
    max = tab[0][j];
    x = 1;
    while (x < 4)
    {
        if (max < tab[x][j])
        {
            count++;
            max = tab[x][j];
        }
        x++;
    }
    if (tabArg[j] != count)
        return (0);
    //printf("leftright : %d\n", count);
    
    return (1);
    
    
}

void ft_print_table(int tab[4][4])
{
    int i;
    int j;
    
    i = 0;
    j = 0;
    while (i < 4)
    {
        while (j < 4)
        {
            printf("%d", tab[i][j]);
            j++;
        }
        i++;
        j = 0;
        printf("\n");
    }
}

int ft_resolve_rush01 (int tabArg)
{
    int tabVide[4][4] = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
    int i;
    int j;
    
    i = 0;
    j = 0;
    while (i < 4)
    {
        while (j < 4)
        {
            tabVide[i][j]++;
            while (ft_compare_case(i, j, tabVide) == 0 && tabVide[i][j] < 5)
                tabVide[i][j]++;
            if (ft_compare_case(i, j, tabVide) == 0 || tabVide[i][j] > 4 || (j == 3 && ft_compare_ligne(i, j, tabVide, tabArg) == 0) || (i == 3 && ft_compare_colonne(i, j, tabVide, tabArg) == 0))
            {
                tabVide[i][j] = 0;
                if (j == 0 )//&& i != 0)
                {
                    i--;
                    j = 2;
                }
                else //if (i != 0 && j != 0)
                    j -= 2;
            }
            j++;
        }
        i++;
        j = 0;
    }
    ft_print_table(&*tabVide);
    return (0);
}


int main (int argc, char **argv)
{
    int i = 1;
    int *tabArg;
    
    tabArg = (int*)malloc(sizeof(int) * 16);
    
    if (argc == 17)                //verifier quil y a assez de parametres
    {
        while (i < 16)
        {
            tabArg[i] = atoi(argv[i]);
            printf("%d", tabArg[i]);
            i++;
        }
        ft_resolve_rush01(tabArg);
    }
}
