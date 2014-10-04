 #include <stdio.h>
 #include <signal.h>

 void afficher(int i);

 int main(void)
{

signal(SIGINT,afficher);
signal(SIGQUIT,afficher);
 while(1){
  }
return 0;
}

 void afficher(int i)
{
printf("hello\n");
printf("%d\n",i);
return;
}
