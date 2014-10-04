#include <stdio.h>
#include <stdlib.h>

int SommeTableau ( int *tableau, int tailledutableau );

int main(int argc, char *argv[])
{

    int tableau[4] = {32, 14, 0, 0};



    SommeTableau(&tableau[4]);





    printf ("%d", tableau[4]);

    return 0;

}

int SommeTableau ( int *tableau, int tailledutableau )
{

    int i;

    for ( i = 0 ; i < tailledutableau ; i++  )



    {

        return tableau [i] + tableau [i];

    }
}
