 #include <stdio.h>
 #include <signal.h>

 void afficher(void)
{
printf("he");
return;
}

 int main(void)
{
signal(SIGHUP,afficher);
while(1){
 }

 return 0;
}
