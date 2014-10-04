  #include "gurobaru.h"
  #include <string.h>
  #include <stdio.h>
 
 void enregistrer(int fd,int i,struct cordonnees *table1)
{
 write(fd,table1[i].id,4);
 write(fd,":",1);
 write(fd,table1[i].name,strlen(table1[i].name));
 write(fd,":\n",2);

 return;
}
