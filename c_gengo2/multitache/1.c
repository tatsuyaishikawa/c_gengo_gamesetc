 #include <stdio.h>
 #include <stdlib.h>

 int main(void)
{
 iti(); 

 ni();

 int *p1=malloc(300)
 int *p2=malloc(300)

 mmap(0x76767676,sizeof(iti),0,1,p1,10);
 mmap(0x7676bbbb,sizeof(ni),0,1,p1,10);

 while(1){
  /* executer 1*/
 /* executer 2*/
 }

 return 0;
}
 
 void iti(void)
{
 printf("iti\n"); 
 return;
}

 void ni(void)
{
 printf("ni\n");
 return;
}
