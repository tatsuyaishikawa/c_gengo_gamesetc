 #include <stdio.h>
 #include "gurobaru.h" 

 void getdata(void)
{
 printf("select data --1 math --2 english\n");
 scanf("%d",&choice);

 switch(choice){
  case 1:
         printf("your math score is %d points\n",table2[j].math);
         break;
  case 2:
         printf("your english score is %d points\n",table2[j].eng);
         break; 
  default:
         printf("invalidd number \n");
         break;
 }

 return;
}
