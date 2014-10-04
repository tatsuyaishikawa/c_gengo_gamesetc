 #include <stdio.h>
 #include <string.h>
 #include <unistd.h>
 #include <stdlib.h>

 int main(int argc,char *argv[])
{
 char moji[20]="";
 if(argc<1){
   printf(" hikisu sukunai \n");
   exit(1);
   } 
 
 char opti=argv[0];

 switch(opti){
   case 'a': strcpy(moji,"iti");
	     break;
   case 'b': strcpy(moji,"ni");
	     break;
   case 'c': strcpy(moji,"san");
	     break;
   }
 
 printf("okabe %s\n",moji);
 return 0; 
}
