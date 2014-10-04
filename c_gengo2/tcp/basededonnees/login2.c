 #include <stdio.h>

 int fd,admi;
 char buf[10];
 
 int login(int argc,char *argv[])
{
 int id,k,count=0;
 char name[10];
 
 /* argv argument ari */ 
 if(argc>0){
 while(1){
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

    if(count==2){
      return 0;
   }
  }
 }
 /* argv argument nashi */
 if(argc==1){
 printf("login with root privilege \n");
 scanf("%d",&admi);

 while(fgets(buf,10,fd)!=admi){
   if(admi==buf){
     return 0;
    }
  }
 }

 return -1;
}
