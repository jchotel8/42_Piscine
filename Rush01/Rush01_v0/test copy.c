#include <stdlib.h>

int main (int argc, char *argv)
{
    int i = 1;
    if (argc == 16)                //verifier quil y a assez de parametres
    {
        int tab[6][6];
        while (i < 5)
        {
            tab[i][0] = atoi(argv[i]);
            tab[i][6] = atoi(argv[i+5]);
            tab[0][i] = atoi(argv[i+10]);
            tab[6][i] = atoi(argv[i+15]);
        }
        
    }
}
