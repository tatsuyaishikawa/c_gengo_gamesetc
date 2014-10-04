 #include <stdio.h>

 int afficher(int *i);

 int main(void)
{
int i=2;
void (*p)(int *);

p=afficher;
i=p(2);
printf("%d\n",i);
}

 int afficher(int *i)
{
return i;
}
