 #include <stdio.h>
 #include <string.h>
 #include <stdlib.h>
 #include <fcntl.h>
 #include "gurobaru.h"

 #define FILENAME "userdata.c"

 int taille;

 void insert(void);
 void getdata(void);
 int  login(void);
 void enregistrer(int fd,int i,struct cordonnees *table1);
 void select1(void);
 void createnewtable(void);
 void datastore(void);

 int main(void)
{
  int refait;
  fd=open(FILENAME,O_WRONLY);
 
  printf("who are you?\n");
   
   do{ 
    if(login()==-1){
     printf("login failed \n");
     }
    count++;
     /* quit loop if login returns 0*/
    }while(count<3);
 
  printf("welcome %s !!\n",table1[k].name); 

  do{
    printf("kansu wo sentaku \n");
    printf("--1  insert new data \n");
    printf("--2 register new data\n");
    printf("--3 chioce table and extract data\n");
    printf("--4 create new table\n");
    printf("--5 \n");
    printf("--6 \n");
    printf("--7 \n");

    scanf("%d",&choice);

    switch(choice){
      case 1: insert();
              break;
      case 2: enregistrer(fd,i,table1);
              break;
      case 3: select1();
              break;
      case 4: createnewtable();
              break;
      case 5:
              break;
      case 6:
              break;
      case 7:
              break;
      default:printf("input 1~7\n");
              break;
    }

    printf("continu?\n");
    refait=scanf("%d",&choice);
  }while(refait);

  printf("end \n");
  return 0;
} 
