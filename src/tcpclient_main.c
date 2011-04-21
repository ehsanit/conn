#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include "tcpclient.c"

/*! 
    @file tcpclient.c
    @author Michal Musialik 
*/

int main(int argc,char *argv[]){
  
  socket_host(argv);
  socket_create();
  socket_binding();
  socket_connection(argv);
  data_passing();  

  return 0;
}
