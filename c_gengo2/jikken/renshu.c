 #include <stdio.h>
 #include <unistd.h>
 #include <stdlib.h>
 #include <sys/types.h>
 #include <signal.h>

 void kansu(void);

 int main(void)
{
 signal(SIGINT,kansu);
 pid_t pd;

 pd=fork();

 // break if ...
 if (pd<0){
   exit(1);
 }

  if(pd==0){
   printf("child\n"); 
  } else {
   while(1){
   sleep(1);
   printf("parent\n");
   }
  }

 return 0;
}

 void kansu(void)
{
// kill(getpid(),SIGTSTP);
   printf("signal received\n");
 return;
}
