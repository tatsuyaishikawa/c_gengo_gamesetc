 #include <stdio.h>
 #include <string.h>
 #include <stdlib.h>
 
 /* decaler d'un mot dans une chaine pour inserer "" */
 char tentuke(char *);

 int main(void)
{
 char a[200],moji[200];
 scanf("%s",a);

 moji=tentuke(a);

 system(moji);
  
 return 0;
}

 char tentuke(char *chaine)
{
  char retu[200];

  /* continer a decaler jusqu'a la premiere occurence de null*/
  for(i=0;i<strlen(chaine);i++){
   
   if(i==0){
    chaine[i]='"';
    }
 
   if(i==strlen(chaine)-1){
    chaine[i]='"';
   }

 return retu;
}
