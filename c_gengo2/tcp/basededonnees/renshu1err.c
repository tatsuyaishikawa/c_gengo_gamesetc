 #include <stdio.h> 
 #include <stdlib.h>

 struct user{
  int id;
  char name[10];
  };
 
 int taille;

 void insert(void);

 int main(void)
{

 printf("youkoso\n");
 printf("how many emory do you need ?\n");
 scanf("%d",&taille); 
 struct user table1[taille]={};

 while(1){
  insert();
 }
 printf("end\n");
 return 0;
}

 void insert(void)
{  
 int iden,i;
 char namae[10];

 printf("insert your data\n");
 
 while(1){
  for(i=0;i<taille;i++){
   printf("id\n");
   scanf("%d",&iden);
   printf("name\n");
   scanf("%s",namae);
   table1[i].id=iden;
   table1[i].name=namae;
   }
 }

 return;
}
