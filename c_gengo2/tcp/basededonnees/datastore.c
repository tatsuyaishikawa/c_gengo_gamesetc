 /* declare equivalent struct with tables to temporally store data */ 
 
 #include <stdlib.h>
 #include <stdio.h>
 #include "hedda.h"

 void datastore(void)
{
 int i=0;
 
 fd1=open("table1.c",4);
 fd2=open("table2.c",4);
 fd3=open("table3.c",4);
 while(!EOF){
  /* read only id part */
  read(fd1,into,4);
  iti[i].id=into; 
  /* read only name part */
  read(fd1,buff,20);
  strcpy(iti[i].name,buff);
  i++;
 }
 
 i=0;

 while(!EOF){
   read(fd2,into,4);
   ni[i].math=into;
   read(fd2,into,4);
   ni[i].eng=into;
   i++;
   }

 i=0;

 while(!EOF){
   read(fd3,buff,20);
   strcpy(san[i].address,buff);
   read(fd3,into,4);
   san[i].tele=into;
   i++;
   }

 close(fd1),close(fd2),close(fd3);
 return;
}
