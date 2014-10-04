 #include <stdio.h>
 #include <stdlib.h>
 #include <unistd.h>

 int main(void)
{
 int nombrejeu=0,nombresec=0,cous=0,rejouer=1;
 /* generer le nombre secret */
 srand(time(NULL));
 nombresec=(rand() % (100 - 1+ 1)) +1;

 do{
  do{
   printf("deviner le nombre \n");
   scanf("%d",&nombrejeu);
   
   if(nombrejeu < nombresec)
    printf("c'est plus\n");
   else if(nombrejeu > nombresec)
    printf("c'est moins\n");
   else if(nombrejeu == nombresec)
    printf("bravo vous avez trouve le nombre mystere!!\n"); 
  }while(nombrejeu != nombresec);
  printf("voulez-vous rejouer?\n  oui =1 non=0");
 scanf("%d",&rejouer);
 }while(rejouer==1);

 printf("merci pour avoir joue\n");
 return 0;
}
