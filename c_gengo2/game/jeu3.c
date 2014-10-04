#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
  
int main(int argc, char *argv[])
{
    int joueurs = 0, nombreJoueur = 0, nombreMystere = 0, coups = 0, rejouer=1;
    const int MAX = 100, MIN = 1;
    srand(time(NULL));
    nombreMystere = (rand() % (MAX - MIN + 1)) + MIN;
 
    printf("Voulez-vous jouer a un ou deux joueurs ?\n\nUn joueur = 1\nDeux joueurs = 2\n\n");
    scanf("%d", &joueurs);
 
    if (joueurs == 2)
        do
        {
            do
            {
                printf("Joueur 1, saissiez un chiffre entre 1 et 100 : ");
                scanf("%d", &nombreMystere);
 
                    if (nombreMystere = 1)
                    {
                            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
                            do
                            {
                                printf("Joueur 2, devinez le nombre mystere : ");
                                scanf("%d", &nombreJoueur);
                                coups++;
                                if (nombreMystere < nombreJoueur)
                                    printf("\nC'est moins !\n\n");
                                else if (nombreMystere > nombreJoueur)
                                    printf("\nC'est plus !\n\n");
                                else if (nombreMystere == nombreJoueur)
                                    printf("\nBravo, vous avez trouve le nombre mystere en %d coups !\n\n", coups);
                            } while (nombreMystere != nombreJoueur);
                    }
 
                    else
                    {
                        printf("Votre saisie est incorrecte, veuillez ressayer.\n\n");
                    }
                }while (nombreMystere > 100 || nombreMystere < 1);
 
            printf("\nVoulez-vous rejouer ?\n\nOui = 1\nNon = 0\n\n");
            scanf("%d", &rejouer);
        } while (rejouer);
 
    else if (joueurs == 1)
        do
        {
            do
            {
                printf("Devinez le nombre mystere : ");
                scanf("%d", &nombreJoueur);
                coups++;
                if (nombreMystere < nombreJoueur)
                    printf("\nC'est moins !\n\n");
                if (nombreMystere > nombreJoueur)
                    printf("\nC'est plus !\n\n");
                if (nombreMystere == nombreJoueur)
                    printf("\nBravo, vous avez trouve le nombre mystere en %d coups !\n\n", coups);
            } while (nombreMystere != nombreJoueur);
            printf("\nVoulez-vous rejouer ?\n\nOui = 1\nNon = 0\n\n");
            scanf("%d", &rejouer);
        } while (rejouer);
 
    system("pause");
    return 0;
}
