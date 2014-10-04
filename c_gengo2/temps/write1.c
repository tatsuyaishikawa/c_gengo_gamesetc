 #include <stdio.h>
 #include <time.h>
 #include <stdlib.h>

 #define FILENAME "/mnt/sdb1/home/S13016/temps/text.c"

 int main(void)
{
 int fd;
 time_t t;
 struct tm tmp;
 char buf[20000];

 time(&t);
  
 fd=fopen(FILENAME,'w');

 while(1){
  fwrite(buf,"1",4,fd);
  fwrite(buf,&tmp,sizeof(tmp),fd);
  fwrite(buf,"\n",2,fd);
  }

  return 0;
}
