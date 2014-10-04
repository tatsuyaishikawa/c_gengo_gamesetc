 #include <stdio.h>
 #include <unistd.h>
 #include <stdlib.h>

 void ki(void);

 int main(void)
{
 int i;
 pid_t pd;
 printf("main %d\n",getpid());
 
 for(i=0;i<10;i++){
  sleep(1);
  if(i==0){
  fork();
  }
 
  else if(i>=1){ 
   if(getppid())
    fork();
   } else{
   }
  printf("parent %d   me %d\n",getppid(),getpid()); 
  }

 ki();

 /*
 if(pd==0){
  printf("child\n");
  }  else if(pd>0){
  while(1){
   sleep(1);
   printf("parent %d\n",pd[0]);
   }
  }
 */
 return 0; 
}
 
 void ki(void)
{
 printf("appele par %d \n",getpid());
 return;
}
