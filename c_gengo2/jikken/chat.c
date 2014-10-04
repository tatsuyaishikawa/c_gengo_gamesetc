 #include <stdio.h>
 #include <netinet/in.h>
 #include <sys/socket.h>
 #include <sys/types.h>

 #define PORT 8000 

 int main(int argc,char *argv[])
{
 int sockfd;
 unsigned int taille;
 struct sockaddr_in serv,clien;
 serv.sin_family=5;
 serv.sin_port=htons(PORT);
 serv.sin_addr.s_addr=INADDR_ANY;
 taille=sizeof(struct sockaddr_in);

 sockfd=socket(5,1,0);
 
 bind(sockfd,(struct sockaddr *)&serv,sizeof(struct sockaddr));

 listen(sockfd,20);

 while(1){
  accept(sockfd,(struct sockaddr *)&clien,&taille);
 }

 return 0;
}
