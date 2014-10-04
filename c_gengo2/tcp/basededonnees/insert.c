 /* how to reopen userdata.c ? modify the option to "a" */
 #include <stdio.h>
 #include <string.h>
 #include "gurobaru.h"


 void insert(void)
{
 int id,cont;
 char name[20];
 
 do{
  printf("please input new user's id \n");
  id=scanf("%d",&id);
  printf("please input new user's id \n");
  scanf("%s",name);
  strcpy(name,name);

  write(id,sizeof(id),fd);
  write(":",2,fd);
  write(name,strlen(name),fd);

  printf("continue? --1  yes --0 no\n");
  cont=scanf("%d",&cont);
  }while(cont); 

 return;
}
