#include <stdio.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <string.h>
#include "tcpserver.c"

/*Author Michal Musialik*/


int main(void){

  host_setup();
  socket_create();
  socket_reusing();
  socket_binding();
  socket_listening();
  new_socket_creation();
  data_passing();
  
  return 0;


}
