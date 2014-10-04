 

 void toroku(void)
{
  sprintf(id,"%d",tataki.id);
  write(fd,id,4);
  write(fd,tataki.name,strlen(tataki.name));
  write(fd,timebuf,strlen(timebuf));

  printf("touroku shuryo\n");
  return;
}
