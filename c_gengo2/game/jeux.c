/* ou stocker des donnes score ?*/
/* comment ouvrir le fichier score */
 #include <stdio.h>
 #include <string.h>
 #include <stdlib.h>

 struct internaute{
  int id;
  char nom[20];
  int score;
  int(*current_game)(); /* 5m*/
  };

 struct internaute player;

 void update_player_data();
 void input_name();
 void jeu1();
 void jeu2();
 void jeu3();
 void show_highscore();
/* void tologin(); */
 void enregister(); /* *?

 int main(void)
{
int choice;

/* if(tologin()==1){
    exit(1);
    } */
 enregister();

printf("welcome to game . please input operation \n");
printf("1------jeu1\n");
printf("2------jeu2\n");
printf("3------jeu3\n");
printf("4------show score\n");
printf("5------input username\n");

 scanf("%d",&choice);
 
 if(choice<1 || choice>5){
  printf("1から4までの数字を入力してください\n");
　
　else if(choice <4){
   if(choice==1){
     player.current_game=jeu1; /* fonction pointeur */
     }   else if(choice==2){
     player.current_game=jeu2;
     }    else{
     player.current_game=jeu3;
     } 
   last_game=choice;  /* batu */

    jeu4();  /* batu */
   }
 else if(choice==4){
   show_highscore();
   }     else if(choice==5){
   printf("change user name please input new user name \n");
   input_name();  /* batu */
   printf("user name was succesfully changed \n");
   }
 
 update_player_data();
  printf("end game \n");
}

/* void tologin(void)
{
 int id;
 char nom[20];
 FILE *fp;

 printf("please login\n");
 printf("id\n");
 scanf("%d",&id);
 printf("nom\n");
 scanf("%s",nom);

 fp=fopen("donnees.h","r");

 while(fgets(hako,20,fp)!=NULL){
   if(player.id=id && player.nom==nom){
       return 0;
      } 
    }
  return 1;
}
*/

 void enregister(void)
{
FILE *fp;

printf("nom de user \n");
input_name();

 player.id=getuid();
 player.score=100;

 fd=fopen("donnees.h","a");

 fwrite(fd,&player,sizeof(struct internaute));
 fclose(fd);

 printf("welcome 　%s to our party!\n",player.nom);
 printf("you have %d credits\n",player.score);
}


 void jeu1(void)
{
int point=0,i;
char boit[i];

 do{
 i=rand()%26;
 printf("please choice umber\n");
 scanf("%d",&deviner);
 if(i==deviner){
   point;
   }
 }while(i==deviner);

 player.my_score1=point;
 /* comment terminer le jeu1*/
 return 0; /* batu */
}

 void jeu2(void)
{
int i=0,point=0;
 
prinf("please select any number\n");
scanf("%d",&i);

 do{
  if((i+rand()%20) == 10){
     point++;
    }
 }while((i+rand()%20)==10){ /* lequel vaut mieux? appler 2fois la meme fonction dans une boucle ou utiliser une variable pour ~*/
 
 player.score=point;
 return 0;
}

 void jeu3(void)
{
 int i=0;point=0;

 printf("please input any number \n");
 scanf("%d",&i);

 do{
  if((i-rand()%3)==0){
      point++;
     }
   }while((i-rand()%3)==0);

  player.score=point;
  return 0;
}
 
 void show_highscore(void)
{
 int input=0;
 FILE *fp;
 /* choisir le nombre de fichier jeu */
 printf("please select file number 1~3\n");
 scanf("%d",&input);

 if(input<1 || input >3){
   printf("please select valid number \n");
   }   

 fp=fopen("jeu"input"score.c",r);

 while(fread(boit,20,fp)!=NULL){
     if(player.current_score < /* batu */){
       player.current_score=/* */;
       }
     }
  fclose(fp);
 return 0;
 /* afficher le point */ /*utiliser struct comme variable generale?*/
 
}

 void input_name(void)
{
char input_name[20];
 /*  batu */
printf("please input new username\n");
player.nom=scanf("%s",input_name);

 if(input_name!=0){
   printf("user name succesfully registerd\n");
  }
 return 0;
}

 void update_player_data(void) /* fread != read */
{
FILE *fp;
int usr_id;
char hako;

 fp=fopen("donnee.h","r");

 if(fp==NULL){
    printf("erorr \n");
   } 
 
  fread(fd,&usr_id,4);
 
  while(usr_id!=player.id){ /* batu */
   for(i=0;i<sizeof(struct user)-4;i++){
      fread(fd,&hako,1); /* BATU */
      fread(fd,&usr_id,4);
      }
    }
  fwrite(fd,&(player.nom),100);
  close(fd);
}
