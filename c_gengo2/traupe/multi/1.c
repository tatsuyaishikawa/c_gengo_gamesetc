
 #include <stdio.h>
 #include <pthread.h>
 #include <unistd.h>

 void *	func(void)
{
 int c=0;

 while(1){
  printf("%d\n",c);
  sleep(1);
  c++;
  }

 return;
}

 int main(void)
{
 int p;

 pthread_create(&p,NULL,(void *)func,NULL);
 
 while(1){}

 return 0;
}
