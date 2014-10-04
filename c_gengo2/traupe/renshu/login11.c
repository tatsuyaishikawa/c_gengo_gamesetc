 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <fcntl.h>
 #include <time.h>
 #include "userdata.c"
 
 int length,fd1,fd2;
 char timebuf[40];
 struct mogura tataki;

 int openopen(char *pass,int id);
 void select1(void);
 void viewdata(void);
 void registeruser(void);
 void timestamp(void);

 int main(int argc,char *argv[])
{
  int id;
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
  fd1=open(filename,4);
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
  close(fd1);close(fd2);
  return 0;  
}
 
 int openopen(char *pass,int id)
{
  int i=-1,j=0,k=0,count=-1;

  do{
   /* mojiretu hikaku */
   y++;
   printf("\n"); /* itigyo goto ni yonde yuku */
   }
  /*
  for(i=0;i<2;i++){
      printf("%s\n",tataki.pass);
      printf("%s \n",pass);
      k=strcmp(pass,tataki.pass);
      printf("%d\n",k);
    if(k==0){
      count++;
      }
    }

  for(j=0;j<2;j++){
    if(id==tataki.id){
      count++;
      }
    }  */ 
  /* if you are new user, you proceed to registeruser() */
  registeruser();
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

 void registeruser(void)
{
  int id;
  char name[20];

  fd2=open("logdata.c",O_WRONLY | O_APPEND);
  printf("toroku\n");
  scanf("%d",&id);
  tataki.id=id;
  scanf("%s",tataki.pass);
 
  timestamp();
  sprintf(id,"%d",tataki.id);
  write(fd2,"id:",4);
  write(fd2,id,4);
  write(fd2,":",4);
  write(fd2,"name:",5);
  write(fd2,tataki.pass,strlen(tataki.pass));
  write(fd2,"\n",2);
  printf("toroku end \n");

  return;
}

 void timestamp(void)
{
  time_t temps;
  struct tm *t;

  time(&temps);
  t=localtime((const time_t *)&temps);
  length=strftime(timebuf,40,"%m/%d/%Y %H:%M:%S>",t);
  
  write(fd2,timebuf,length);
  return;
}
