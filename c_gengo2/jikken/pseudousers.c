 #include <stdio.h>
 #include <string.h>
 #include <netinet/in.h>
 #include <sys/socket.h>
 #include <sys/types.h>
 #include <unistd.h>
 #include <stdlib.h>
 #include <signal.h>
 
 #define PORT 8000

 void proce(char *ado);
 
 char buf[2000],ado[50];
 /*strcpy(ado,argv[1]);*/
 
 int main(int argc,char *argv[])
{
 signal(SIGTSTP,proce);

 while(1){
  }
 
 return 0;
}

 void proce(char *ado)
{
 pid_t pd;
 pd=getpid();

  /* attribute process id and connect to livechat.c */
 while(1){
  if(pd==0){
  int sockfd;
  struct sockaddr_in clien;
 
  clien.sin_family=5;
  clien.sin_port=htons(PORT);
  clien.sin_addr.s_addr=gethostbyname("192.168.0.176"); /* generer ip automatiquement*/
  unsigned int taille=sizeof(struct sockaddr_in);

  sockfd=socket(5,1,0);
   
  connect(sockfd,(struct sockaddr_in *)&clien,taille); 
 
  while(1){
   send(sockfd,"jiji",sizeof(struct sockaddr_in),0);
   recv(sockfd,"jiji",sizeof(struct sockaddr_in),0); 

   printf("%s\n",buf);/* print message received from chat server*/ 
   }
   close(sockfd);
 } else if(pd>0){
  printf("parent process\n");
 } else{
  printf("process removed\n");
 }
}
 return;
}
