 #include <stdio.h> 
 #include <stdlib.h>
 #include <string.h>
 #include <fcntl.h>
 #include "enregistrer.c"

 struct user{
  int id;
  char name[10];
  };

 int taille,i;

 int fd=open("userdata.c",O_WRONLY);
 void insert(struct user *table1);
 void enregistrer(int fd,int i,struct user *table1);

 int main(void)
{

 printf("youkoso\n");
 printf("how many emory do you need ?\n");
 scanf("%d",&taille); 

 struct user table1[taille];
 
 insert(table1);

 printf("end\n");
 close(fd);
 return 0;
}

 void insert(struct user *table1)
{  
 int iden,input;
 char namae[10];

 printf("insert your data\n");
 
  for(i=0;i<taille;i++){
   printf("id\n");
   scanf("%d",&iden);
   printf("name\n");
   scanf("%s",namae);
   
   printf("register  datas? --1 yes --2 no\n");
   scanf("%d",&input);
  
   if(input ==1)
   enregistrer(fd,i,table1);
   }

  /*for(i=0;i<taille;i++){
   printf("%d %s\n",table1[i].id,table1[i].name);
   }*/

 return;
}
