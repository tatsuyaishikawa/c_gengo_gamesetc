 /* 30.5.2014  how to realize relational data table */ 
 /* 30.5.2014  can not display id in seekng */

 #include <stdio.h>
 #include <fcntl.h>
 #include <unistd.h>
 #include <stdlib.h>
 #include "gurobaru.h"

 void select1(void)
{
 int refait=1,i=0; /* i for element number in table */
 char cible[20],name[20],buff[20];

 do{
 printf(" chioce table number \n");
 scanf("%s",cible);
 
 /* refuse connection if table does not exist */
 if((fd=open(cible,O_RDONLY))==-1){
   perror("does not exist\n");
   exit(1);
   }
 
 /* enter the element name you seek */
 printf("enter element name\n");
 scanf("%s",name);
 /* seek corresponding elemnts from target table */
 do{
  read(fd,buff,20);
  if(buff == name){
   printf("id    choice  %s\n",buff);
   break;
   }  
  i++;
 }while(buff !=name); 
 
 i=0;
 printf("continue? --1 yes --0 no\n");
 scanf("%d",&refait);
 }while(refait); 
 
 return;
}
