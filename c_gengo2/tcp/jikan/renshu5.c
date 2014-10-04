 #include <stdio.h>
 #include <time.h>
 #include <unistd.h>
 #include <string.h>
 
 int main(int argc,char *argv[])
{
  time_t taimu;
  int count=0,n;
  signed int hdif,mdif,sdif,firsth,firstm,firsts;
  char commande[200],buff[100];
  FILE *pp;

  n=5;
  strcpy(commande,argv[1]);
  time(&taimu);
  pp=popen(commande,"r"); /* date command is best */

  struct tm data[n];  /* need to receive a number from command line argument */

  /* execute program 5 times */ 
  while(count<n){
   data[count]=*localtime(&taimu);
   /* transfer data to tm struct */
   fgets(buff,10,pp);/* execute program */ 
   if(count==0){
     firsth=data[count].tm_hour; /* get time */
     firstm=data[count].tm_min;
     firsts=data[count].tm_sec;
     }
   sleep(1);
   count++;
   }
  
  /* calculate time difference hour*/
  hdif=data[count-1].tm_hour-firsth;
 
  /* calculate time difference */
  if((data[count-1].tm_min-firstm)<0){
    mdif=(data[count-1].tm_min+60)-firstm;
    hdif--;
  } else{
    mdif=data[count-1].tm_min-firstm;
    }

  /* calculate time difference second */
  if((data[count-1].tm_sec-firsts)<0){
    sdif=(data[count-1].tm_sec+60)-firsts;
    mdif--;
    } else{
　　sdif
 
  printf("time difference is %d h %d m %d s\n",hdif,mdif,sdif); 
  pclose(pp);
  return 0; 
}
