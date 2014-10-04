 #include <stdio.h>
 #include <signal.h>

 int main(void)
{
__sighandler_t i;
i=signal(SIGINT,SIG_IGN);

while(1){
 }
return 0;
}
