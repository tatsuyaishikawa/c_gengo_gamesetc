 #include <stdio.h>
 #include <linux/tcp.h>
 #include <string.h>

 int main(void)
{
  struct tcp_info user;


  printf("%c\n",user.tcpi_state);  
  printf("%c\n",user.tcpi_ca_state);  
  printf("%c\n",user.tcpi_retransmits);  
  printf("%c\n",user.tcpi_probes);  
  printf("%c\n",user.tcpi_backoff);  
  printf("%c\n",user.tcpi_options);  
  printf("%c\n",user.tcpi_snd_wscale);  
  printf("%u\n",user.tcpi_rto);  
  printf("%u\n",user.tcpi_ato);  
  printf("%u\n",user.tcpi_snd_mss);  
  printf("%u\n",user.tcpi_rcv_mss);  
  

  printf("%d\n",sizeof(struct tcp_info));
  return 0;
}
