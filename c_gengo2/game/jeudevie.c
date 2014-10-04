#include <stdio.h>
#include <stdlib.h>
 
int main()
{
    int i,j;
    int table [7][7];
    int nbIterator=0;
 
    printf("\n saisissez le nombre d\'iterations : \n");
    scanf("%d",&nbIterator);
 
    printf("la table generee est : \n ");
 
    for( i =0;i<7;i++)
    {
        for( j =0;j<7;j++)
        {
            if(i==0 ||i==6 || j==0 || j==6)
            {
                table[i][j]=2;
            }
            else if(i % 2 == 0)
            {
                table[i][j]=1;
            }
            else{
                table[i][j]=0;
            }
        }
    }
 
    for(i=1;i<6;i++)
    {
        for(j=1;j<6;j++)
        {
            printf("%d",table[i][j]);
            //printf("\n");
        }
 
        printf("\n");
    }
 
    printf("\n\n\n");
 
    int nbVoisine=0;
    while(nbIterator>0)
    {
 
       for(i=0;i<7;i++)
       {
           for(j=0;j<7;j++)
           {
                    if(table[i+1][j]==1)
                    {
                        nbVoisine++;
                    }
                    if(table[i-1][j]==1)
                    {
                        nbVoisine++;
                    }
                     if(table[i][j+1]==1)
                    {
                        nbVoisine++;
                    }
                    if(table[i][j-1]==1)
                    {
                        nbVoisine++;
                    }
                    if(table[i-1][j+1]==1)
                    {
                        nbVoisine++;
                    }
                    if(table[i-1][j-1]==1)
                    {
                        nbVoisine++;
                    }
                    if(table[i+1][j+1]==1)
                    {
                        nbVoisine++;
                    }
                    if(table[i+1][j-1]==1)
                    {
                        nbVoisine++;
                    }
 
                    if(nbVoisine==3)
                    {
                        table[i][j]=1;
                    }
                    else if(nbVoisine<2 || nbVoisine >3)
                    {
                        table[i][j]=0;
                    }
 
             nbVoisine=0;
 
           }
        }
 
 
         for(i=1 ;i<6;i++)
        {
            for(j=1;j<6;j++)
            {
                printf("%d",table[i][j]);
            }
                printf("\n");
        }
 
        printf("\n\n\n");
        nbIterator--;
    }
 
    return 0;
}
