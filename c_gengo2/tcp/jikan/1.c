 #include <stdio.h>
 #include <time.h>
 #include <signal.h>
 #include <stdlib.h>

 struct tm t;
 time_t temps;

 void *koushin(void);

 int main(void)
{
  int minute,seconde,fun=0,byo=0;
  int count=0;
   
  signal(SIGINT,(void *)koushin());
   time(&temps);
   t=*localtime(&temps);
   minute=t.tm_min;
   seconde=t.tm_sec;

  while(count<30){
   sleep(1);
   printf("mac       starttime    lasttime  \n");
   printf("%d         %d  %d      %d   %d   \n",count,minute,seconde,t.tm_min+fun,t.tm_sec+byo);
   count++;
   if(fun>=60){
   fun=0;
   }
   fun++;
   if(byo){
   byo++;
   }

  }

  return 0;
}

 void *koushin(void)
{
  t=*localtime(&temps); /* 再審の時間を取得する関数*/
  return;
}
