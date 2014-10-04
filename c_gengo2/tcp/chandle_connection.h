 
 
 void chandle_connection(int sockfd,struct sockaddr_in *serv)
{
 /* ptr pointer of "http://"  ,  moji stockes the value of http request and so on */
 char moji[500];
 char buf[500],*ptr;
 int fd;

 /* dare niokuri masuka */
 printf("port %d : add %s\n",serv.sin_port,serv.sin_addr);

 moji=send_to(sockfd,buf,);
 
 /* 1,http?
  2,include get or post? */
 ptr=strstr("http/",moji);
 if(ptr==NULL){
  printf("invalide request\n");
 }  else{
 /*? */  
 *ptr=0;
 ptr=NULL;
 
 /*GET or POst appears firstly*/
  if(strncmp(moji,"GET",4)==0){
  /* deplacer le pointeur , +4*/
  /* #####################################################################
#################################
########################
#################
############  */ 
   ptr=moji+4; 
  }  
  if(strncmp(moji,"POST",5)==0){
   ptr=moji+5;
  } 
 

 /*3, which file you need?*/
 /* 20:25~21:05 / de owaru=forward to index.html*/
 /* 
  how to indicate the target file?*/
 /* image that in moji var, we have  
 GET http://localhost/S13016/index.html*/
 if(ptr[strlen(ptr)-1]=='/')
   strcat(ptr,"index.html");
   
  /* indicate repertoire racine */
  strcpy(moji,"./S13016");
  /* append url to request ? gyakudeha  gyakunisitoita?*/
 /* ##############################
##########################
################################ */
  strcat(moji,ptr);
  /* file open which file ?*/
 /* ################################################
###############################################
###########################################
###################    そもそもファイルはhttp陸エスとの中に
最初から含まれていると思うのですが */
  fd=open(moji,O_RDONLY);
  printf("%s akemasu\n",moji); 
 
  /* file not found */
  if(fd==-1){
   printf("404 not found \n");
  }  else{
  /* display file contens */
  printf("200 ok\n");
  send_string(sockfd,"http/1.0 200 ok\n");
  send_string(sockfd,"server tiny webserver\n");
  close(fd);
  }
 }
 
 return;
}
