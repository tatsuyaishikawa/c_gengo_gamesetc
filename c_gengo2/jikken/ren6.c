 #include <stdio.h>
 #include <string.h>
 #include <unistd.h>
 #include <stdlib.h>
 #include <signal.h>

 void mykill(void);
 void rei(void);

 int main(void)
{
 signal(SIGINT,mykill);

 int i;
 pid_t pd;
 printf("main %d\n",getpid());
  
  fork();
 
  printf("je suis %d et mon pere %d\n",getpid(),getppid());
 
 /*
  else if(i>=1){ 
   if(getppid())
    fork();
   } else{
   }
  printf("parent %d   me %d\n",getppid(),getpid()); 
  }
  */

 rei();
 pd=getpid();

 if(pd==0){
  printf("child\n");
  }  else if(pd>0){
  while(1){
   sleep(1);
   printf("parent \n");
   }
  }

 return 0; 
}
 
 void mykill(void)
{
 int ai;
 printf("which pid you kill ? \n");
 
 scanf("%d",&ai);
 
 kill(ai,0);

 return;
}
 
 void rei(void)
{ 
 char a[20];

 scanf("%s",a);
 
 system(a);
 return;
}
