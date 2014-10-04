 #include <stdio.h>
 #include <string.h>

 int main(void)
{
 char boit[3];
 int i,x=0;

 while(1){
  for(i=0;i<3;i++){
   printf("%c",boit[i]='1');
   }
  boit[x]=0;

  if(x>0 && x<3){
   boit[x]='\n';
   x++;
   boit[x]='0';
   }while(x<3);

  if(x>0 && x<3){
   boit[x]='\n';
   x--;
   boit[x]='0';
   }while(x>0);
  }

 return 0;
 
}
