 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include <netinet/in.h>
  
 int main(void)
{
int sockfd;
int bin,con;
struct sockaddr_in donne,client;
char hako[2000000];

donne.sin_port=80;
unsigned int adoresuclient=11000000101010000000000001101101; /* 192.168.0.109*/
donne.sin_addr=adoresuclient; /**/
donne.sin_family=1;
unsigned int adoresuserver=11000000101010000000000001100110;
client.sin_addr=adoresuserver; /**/

sockfd=socket(donne.sin_family,5,0);

if(sockfd==-1){
  printf("era\n");
  exit(1);
  }

 bin=bind(sockfd,donne.sin_addr,sizeof(donne.sin_addr));
 
if(bin==-1){
  printf("bin era\n");
  exit(1);
  }

 con=connect(sockfd,client.sin_addr,sizeof(client.sin_addr));
 
 if(con==-1){
  printf("con era\n");
  exit(1);
  }

 while(1){
  recv(sockfd,hako,10,0);
  }
 
 return 0;
}
