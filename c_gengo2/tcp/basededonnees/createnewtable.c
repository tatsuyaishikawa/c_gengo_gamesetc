 /* 4.6.2014   
  1, faut executer chmod 755 [file] pour donner la privilege
  end 2, si char est indique,en determiner la taill */

 #include <unistd.h>
 #include <fcntl.h>
 
 void createnewtable(void)
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
  system("vim"); 
  /*open new file */
  fd=open(filename,O_CREATE | O_RDWR); 

  write(fd,"struct",20);
  write(fd,structname,20);
  write(fd,"{",4); 
  /* repeate */ 
   do{
    printf("enter the type of elemetnt\n");
    scanf("%s",type);
    printf("enter the name of elements\n");
    scanf("%s",field);
    write(fd,type,5);

    if(field=="char"){
     printf("you choice simple char type or string type ?\n");
     scanf("%d",&choice);
     
     if(choice){
      printf("indicate the size of string\n");
      scanf("%d",&taille);
  
      write(fd,field,strlen(field));
      write(fd,"[",1);
      write(fd,taille,sizeof(taille));
      write(fd,"]",1);
      } else{
    /* if symple char */    
          write(fd,field,strlen(field));
        }
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
