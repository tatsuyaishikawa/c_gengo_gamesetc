 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include "userdata.c"

 int openopen(char *pass,int id);
 void select1(void);
 void viewdata(void);

 int main(int argc,char *argv[])
{
  int fd,id;
  int resultat,choice;
  char filename[200],pass[15];
  /* password and id authentification */
  strcpy(filename,argv[1]);
  
  printf("please entre your password and id \n");
  /*scanf("%s",pass);
  scanf("%d",&id);*/

  fgets(pass,10,stdin);
  scanf("%d",&id);

  if(resultat==-1 || resultat==0){
    printf("login failed\n");
    exit(1);
    }
  fd=open(filename,4);
  printf("welcom to mysql\n");
  printf("1-- search word from database  2-- check database file 3-- quit this program\n");

  scanf("%d",&choice);
  switch(choice){

    case 1:select1();
           break;
    case 2:viewdata();
           break;
    case 3:printf("bye\n");
           exit(1);
    default: printf("please input valid number\n");
           break;
    }
  /* 呼び出されたファイルの側で　 パスワードを保存するファイル　とユーザIDを保存するファイル相互に問合せ */
  printf("終了します\n");
  return 0;  
}
 
 int openopen(char *pass,int id)
{
  int i=-1,j=0,k=0,count=-1;

  for(i=0;i<2;i++){
      printf("%s\n",tataki[i].pass);
      printf("%s \n",pass);
      k=strcmp(pass,tataki[i].pass);
      printf("%d\n",k);
    if(k==0){
      count++;
      }
    }

  for(j=0;j<2;j++){
    if(id==tataki[j].id){
      count++;
      }
    }   
  return count; 
}

 void select1(void)
{
 /* printf("1-- select  2-- update  3-- where 4-- quit\n");
  switch(choice){
    case 1:
    case 2:
    case 3:
    case 4: 
    case default:
    } */

  return;
}

 void viewdata(void)
{
/* int fd;
 prin 
 fd=open(filename2,R_ONLY);
 
 while(buff){
   read(fd,buff,4);
   printf("%s\n",buff);
   }
 */
 return;
} 
