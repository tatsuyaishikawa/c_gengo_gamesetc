 #include <stdio.h>
 #include <string.h>
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <fcntl.h>
 #include "userdata.c"
  

  int i=0,fd,length;
  char timebuf[40];
 struct mogura tataki[1]={
 {0,""}};;

 void timestamp(void);

 int main(void)
{
  fd=open("logdata.c",O_WRONLY | O_APPEND);
  printf("welcom\n");
  printf("toroku\n");
   tataki[0].id=i; /* newest id assign to new user */
   printf("%d\n",tataki[0].id); 
   printf("please register your name\n");
   scanf("%s",tataki[0].name); /* need to register in the same rubrique que id*/
   
   char id[4];
   timestamp();
   sprintf(id,"%4d",tataki[0].id); 
   write(fd,"id:",3);
   write(fd,id,4);
   write(fd,":",4);
   write(fd,"name:",5);
   write(fd,tataki[0].name,strlen(tataki[0].name));
   write(fd,"\n",2);
   printf("toroku shuryo\n");
   close(fd);
   return 0;
}

 void timestamp(void)
{  
 time_t temps;
 struct tm *t;
 
 time(&temps);
 t=localtime((const time_t *)&temps);
 length=strftime(timebuf,40,"%m/%d/%Y %H:%M:%S>",t);
 write(fd,timebuf,length);
 return;
}
