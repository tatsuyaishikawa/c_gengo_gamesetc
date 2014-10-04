 #include <stdio.h>
 #include <string.h>
 
 int fd,i[1],id,j,k,rel1,rel2;
 char name[5],myname[5];
  
 int idcheck(void);
 int namecheck(void);

 int main(void)
{
 fd=open("datalog.c",5);
 printf("id\n");
 scanf("%d",&id);
 printf("name\n");
 scanf("%s",myname);

 rel1=idcheck();
 rel2=namecheck();

 if(rel1+rel2 == 2){
   printf("login reussi\n");
   }
 
 close(fd);
 return 0;
}

 int idcheck(void)
{
 while(i[0]!=0){
  i[0]=read(fd,i[0],4);
  if(i[0]== id){
   return 1;
   }  
  }
 return 0;
} 

 int namecheck(void)
{
 while(name!='\0'){
  sprintf(name,"%d",read(fd,name,5));
  if(name==myname){
   return 1;
   }
  }
  return 0;
}
