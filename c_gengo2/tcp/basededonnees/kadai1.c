 #include <stdio.h>
 #include <unistd.h>
 #include <fcntl.h>
 #include <string.h>
 
 
 int main(void)
{
 int fd,refait=1,input=0;
 char filename[20],structname[20],tablename[20],type[8],field[20]; 

 do{
  printf("create new file in which  you store the new table \n");
  scanf("%s",filename);
  printf("name your new structure \n");
  scanf("%s",structname);
  printf("name your new table\n");
  scanf("%s",tablename);
   
 
   /* choice data key and types  and so on  */
  /* creation de fichier pour stocker des donnees de la nouvelle table */
  /*open new file */
  fd=open(filename,O_CREAT | O_RDWR); 

  write(fd,"struct",6);
  write(fd,structname,strlen(structname));
  write(fd,"{",1);
  write(fd,"\n\n",4);
  /* repeate */ 
   do{
    printf("enter the type of elemetnt\n");
    scanf("%s",type);
    printf("enter the name of elements\n");
    scanf("%s",field);
    write(fd,type,strlen(type));
    write(fd,field,strlen(field));
    write(fd,";",1);
    write(fd,"\n",2);
 
    printf("add more datas? --1 yes --no \n");
    scanf("%d",&input); 
    }while(input);

   write(fd,"};",4);
   write(fd,tablename,20);
   write(fd,"\n\n",4);
 
   close(fd);
   printf("continue? --1 yes --0 no\n");
   scanf("%d",&refait);
  }while(refait);
 
 return;
}
