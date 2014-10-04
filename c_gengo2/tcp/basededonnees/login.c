
 /*  30.5.2014  how to memorise the current user ?*/
 /*  in this program, put current user id   to cuserid variale */
 
 #include <stdio.h>
 #include "gurobaru.h"
 
 int login(void)
{
 int id,refait;
 char name[10];
  
  do{
    printf("who are you? input your id and your name\n");
    printf("your id\n");
    scanf("%d",&id);
    printf("your name\n");
    scanf("%s",name);

    for(k=0;k<2;k++){
      if(id==table1[k].id){
        count++;
        }
      if(name==table1[k].name){
        count++;
        }
     }

    if(count==2){  /* if id and name are matching */
      cuserid=table1[k].id;
      return 0;
   }
  }while(refait); 
 
 return -1;
}
