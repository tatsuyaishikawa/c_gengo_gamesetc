 #include <stdio.h>

 struct iti{
  char moji1;
  };

 struct ni{
  char moji2;
  };

 struct san{
  char moji3;
  };

 int main(void)
{
  int fd,fd2,i=1;
  char buf[20];
  struct iti one;struct ni two;struct san three;

  fd=fopen("target2.c","r");
  fd2=fopen("kakikomi.c","w");
 
  while(!EOF){
    /* station mac line    recognize*/
    if(fread(buf,6,6,fd)=="second"){
      printf("\n");
      while(!EOF){
        switch(i){
          case 1: while(fread(one.moji1,1,1,fd)!=','){
                  fwrite(one.moji1,1,1,fd2);
                  }
                  i++; /* 処理を抜けた後どこに戻る*/
                  break;
          case 2: while(fread(two.moji2,1,1,fd)!=','){
                  fwrite(two.moji2,1,1,fd2);
                  }
                  i++;
                  break; 
          case 3: while(fread(three.moji3,1,1,fd)){
                  fwrite(three.moji3,1,1,fd2);
                  }
                  i=1;
                  break;
          default:printf("batu\n");
                  break;
                 }

            } 
        }
      }

  printf("kakikomi end \n"); 
  fclose(fd);fclose(fd2);
  return 0;
}
