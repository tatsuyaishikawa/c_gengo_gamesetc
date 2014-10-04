 #include <signal.h>
 #include <stdio.h>
 
 void sig_alarm()
{
return;
}
 int main(void)
{
 int i=2;
 signal(SIGALRM,sig_alarm);
 
 while(1){
  alarm(1000);
  printf("%d",i);
  alarm(1000);
  }

 return 0;
}
