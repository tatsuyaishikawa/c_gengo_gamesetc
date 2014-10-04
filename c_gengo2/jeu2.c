#include <stdio.h>
#include <stdlib.h>
#include <time.h>
  
int main(int argc, char *argv[])
{
    int joueurs = 0, difficulte = 0, nombreJoueur = 0, nombreMystere = 0, coups = 0, rejouer=1;
     
    do
    {
        do
        {
            printf("\nVoulez-vous jouer a un ou deux joueurs ?\n1 = un joueur\n2 = deux joueurs\n");
            scanf("%d", &joueurs);
 
            if (joueurs == 2)
            {
                do
                {
                    printf("\nChoisissez votre niveau de difficulte :\n1 : Niveau 1 (entre 1 et 100)\n2 : Niveau 2 (entre 1 et 1000)\n1 : Niveau 3 (entre 1 et 10000)\n");
                    scanf("%d", &difficulte);
 
                    if (difficulte == 1)
                    {
                        do
                        {
                            printf("\nJoueur 1, saissiez un chiffre entre 1 et 100 : ");
                            scanf("%d", &nombreMystere);
 
                                if (nombreMystere <= 100 && nombreMystere >= 1)
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
                    }
 
                    if (difficulte == 2)
                    {
                        do
                        {
                            printf("\nJoueur 1, saissiez un chiffre entre 1 et 1000 : ");
                            scanf("%d", &nombreMystere);
 
                                if (nombreMystere <= 1000 && nombreMystere >= 1)
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
 
                        }while (nombreMystere > 1000 || nombreMystere < 1);
                    }
 
                    if (difficulte == 3)
                    {
                        do
                        {
                            printf("\nJoueur 1, saissiez un chiffre entre 1 et 10000 : ");
                            scanf("%d", &nombreMystere);
 
                                if (nombreMystere <= 10000 && nombreMystere >= 1)
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
 
                                }while (nombreMystere > 10000 || nombreMystere < 1);
                    }
 
                    else
                    {
                        printf("Votre saisie est incorrecte, veuillez ressayer.\n\n");
                    }
 
                }while (difficulte > 3 || difficulte < 1);
 
            }
 
            else if (joueurs == 1)
            {
 
                do
                {
                    printf("\nChoisissez votre niveau de difficulte :\n1 : Niveau 1 (entre 1 et 100)\n2 : Niveau 2 (entre 1 et 1000)\n1 : Niveau 3 (entre 1 et 10000)\n");
                    scanf("%d", &difficulte);
 
                    if (difficulte == 1)
                    {
                        int nombreMaximum = 100, nombreMinimum = 1;
                        srand(time(NULL));
                        nombreMystere = (rand() % (nombreMaximum - nombreMinimum + 1)) + nombreMinimum;
 
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
                    }
 
                    if (difficulte == 2)
                    {
                        int nombreMaximum = 1000, nombreMinimum = 1;
                        srand(time(NULL));
                        nombreMystere = (rand() % (nombreMaximum - nombreMinimum + 1)) + nombreMinimum;
 
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
                    }
 
                    if (difficulte == 3)
                    {
                        int nombreMaximum = 10000, nombreMinimum = 1;
                        srand(time(NULL));
                        nombreMystere = (rand() % (nombreMaximum - nombreMinimum + 1)) + nombreMinimum;
 
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
                    }
         
                }while (difficulte > 3 || difficulte < 1);
            }
 
        }while (joueurs >2 || joueurs < 1);
 
    printf("\nVoulez-vous rejouer ?\n\nOui = 1\nNon = 0\n\n");
    scanf("%d", &rejouer);
 
    } while (rejouer);
 
    system("pause");
    return 0;
}
