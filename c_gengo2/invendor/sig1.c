 #include <stdio.h>
 #include <signal.h>

 int main()
{
int i;

scanf("%d",&i);

if(signal(SIGHUP,SIG_DFL)==SIG_ERR){
   printf("ji");
   exit(1);
   }

  if(signal(SIGQUIT,SIG_DFL)==SIG_ERR){
    printf("jiji");
    exit(1);
    }

  signal(SIGSTOP,SIG_IGN);

  sleep(i);
  exit(0);

}

