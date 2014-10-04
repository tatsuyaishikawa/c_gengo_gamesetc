 #include <stdio.h>
 #include <string.h>
 #include <netinet/in.h>
 #include <sys/socket.h>
 #include <sys/types.h>
 #include <unistd.h>
 #include <stdlib.h>
 #include <signal.h>
 
 #define PORT 8000

 pid_t pd;
 pd=getpid();

 void proce(void);
 void mykill(void);
 
 char buf[2000],ado[50];
 /*strcpy(ado,argv[1]);*/
 
 int main(void)
{

 signal(SIGINT,proce);
 /*signal(SIGTSTP,mykill);*/

 while(1){
  }
 
 return 0;
}

 void proce(void)
{

 signal(SIGTSTP,mykill);

  fork();
  pid_t pd2=getpid();

  /* attribute process id and connect to livechat.c */
  if(pd2==0){
   while(1){
   printf("je suis le fils de %d \n",getppid());/* print message received from chat server*/ 
   }
  }  else{
  while(1){
   sleep(1);
   printf("parent process %d\n",pd2);
   }
 }

 return;
}

 void mykill(void)
{
 int n=getpid();
 printf("%d\n",n);

 
 return;
}
