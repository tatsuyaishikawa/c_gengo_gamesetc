 #include <stdio.h>
 #include <unistd.h>
 #include <stdlib.h>
 #include <string.h>

 int main(void)
{
 pid_t pd;
 int desc[2];
 char msg[20];
 
 pipe(desc);
 pd=fork();

 if(pd==0){
  printf("salut je suis le fils de %d\n",getppid());
  read(desc[0],msg,strlen(msg));
  printf("fils pid %d recu le message suivant du pere %s\n",getpid(),msg);
 } else{
  sprintf(msg,"jijijij");
  printf("salut je suis pere de fils pid %d envoie le message suivant %s\n",getpid(),msg); 
  write(desc[1],msg,strlen(msg));
 }

 return 0;

}
