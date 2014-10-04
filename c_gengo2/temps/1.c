 #include <stdio.h>
 #include <string.h>
 #include <sys/time.h>
 #include <sys/types.h>
 #include <unistd.h>

 int main(void)
{
 struct timeval t;
 int i;
 fd_set fd;
 
 FD_ZERO(&fd);
 FD_SET(0,&fd);
 
 t.tv_sec=0;
 t.tv_usec=0;

  i=select(0,&fd,NULL,NULL,&t);
  if(i){
  printf("he\n");
  }
 return 0;
}
