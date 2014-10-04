 #include <stdio.h>
 #include <stdlib.h>

 void iti(void):
 void ni(void);

 int main(void)
{
 int *p[1000000];
 int i=0;

 /*mmap(0x76767676,sizeof(iti),0,1,p1,10);
 mmap(0x7676bbbb,sizeof(ni),0,1,p1,10);*/

 while(1){
  p[i]=(void *)malloc(4);
  p[i+1]=(void *)malloc(4);
  p[i]=iti;
  p[i+1]=ni;
  iti();
  ni();
  i=i+2;
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
