 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>

 void jeu1(int p);
 void jeu2(int p);

 int main(void)
{
int p=5; /* point initial */
int i=0,colon=0,ligne=0,choice=0;
int boit[2][4];

memset(boit,0,8);

 printf("welcome to tirage au sort !\n!");
 
  do{
   printf("please input the number of a box \n");

  colon=rand()%2;
  ligne=rand()%4;
  boit[colon][ligne]=1;

  scanf("%d",&colon);scanf("%d",&ligne);
   
 if(boit[colon][ligne]!=1){
   printf("you won \n");
   break;
   }  else{
  printf(" you loose\n");
  p--;
  colon=0;
  ligne=0;
  }
 }while(p>0);
 
 if(p==0){
   printf("see you again \n");
   exit(1);
   }

 printf("you can play another game\n"); 
 printf("please select game\n");
 printf("----1------   math \n");
 printf("----2------   go \n");
 printf("----0------  quit\n");
 scanf("%d",&choice);
 
 switch(choice){
  
 case 1:
   jeu1(p);
 case 2:
   jeu2(p);
 case 0: 
   printf("bye\n");
   break;
 default:
   printf("please input valid number \n");
  break;
 }

}



 void jeu1(int p)
{
 
 int x=0,y=0,i=0;
 int ennemie[1][3],hako[5][5];

 printf("you have %d points\n",p);

 do{
 if(y/2==0){
  /* vers la droite */
 do{
   /* effacer des ennemies pour les deplacer */
    ennemie[x][y]=0;
    ennemie[x+1][y]=0;
    ennemie[x+2][y]=0;
  x++;
  
   /* deplacer des ennemies */
    ennemie[x][y]=1;
    ennemie[x+1][y]=1;
    ennemie[x+2][y]=1;
  }while(x!=4);
  y++;
 }    
     else{
 do{
   /* effacer des ennemies pour les deplacer */
    ennemie[x][y]=0;
    ennemie[x-1][y]=0;
    ennemie[x-2][y]=0;
  x--;
  
   /* deplacer des ennemies */
    ennemie[x][y]=1;
    ennemie[x-1][y]=1;
    ennemie[x-2][y]=1;
  }while(x!=0);
  y++;
 }
  }while(y!=4); /* la fin du jeu */


/* des ennemies descendent d'une colonne       ligne nombre pair,incrementer   ligne nombre impair decrementer */
  
/*  fin de jeu      des ennemies invahissent la colonne ou je me trouve */

 /* shooting 　probleme de vitesse */

 
}
 
 void jeu2(int p)
{

}
