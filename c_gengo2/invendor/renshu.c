 #include <stdio.h>
 #include <signal.h>

 void afficher(void);

 int main(void)
{
 int hako[3][4];
 int x,y;

 while(1){
  for(y=0;y<3;y++){
   for(x=0;x<4;x++){
    sleep(1);
    afficher();
    }
   }
  }

 return 0;
}

 void afficher(void)
{
 int boit[3][4];
 int x,y;

 for(y=0;y<3;y++){
  for(x=0;x<4;x++){
   sleep(1);
   boit[y][x]=1;
   printf("%d",boit[x][y]);
   }
  }
 return;
}
