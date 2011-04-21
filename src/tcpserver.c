/*! 
    @file tcpserver.c
    @author Michal Musialik 
*/

#include <stdio.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h> 
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <string.h>
#include "mask_con.c"

#define IP_BUFFER_LENGTH 200 /*Buffer for IP adress*/
#define PORT 9600 /*IP port adress*/
#define BUFFER_SIZE 32 /*Buffer size of messages*/
#define BACKLOG 3 //Number of connection pending

int socket_tcp; /*tcp socket name*/
int new_socket;/*Name of the oncomming socket connection*/
int byte; /*Byte of message*/
int addrlen; /*Length of an adress*/
int on = 1;/*setcokopt option_value argument*/
char ip_buffer[IP_BUFFER_LENGTH];/*Host ip */
char reciv_data[BUFFER_SIZE]; /*Recived data*/

struct sockaddr_in client;/*Struct for socket adress*/
struct sockaddr_in server;/*Struct for socket adress*/


/*Function to get hosts IP information*/
int host_setup(){

  struct hostent * Host ;
  gethostname(ip_buffer , IP_BUFFER_LENGTH);
  printf("%s\n", ip_buffer);
  Host = ( struct hostent * )gethostbyname(ip_buffer);
  printf("Host name : %s\n", Host->h_name) ;
  printf("Host IP Address : %s\n", inet_ntoa(*((struct in_addr *)Host->h_addr)));

  return 0; 

}

/*!
    \brief Creates a TCP socket
*/
int socket_create(){

 if(( socket_tcp = socket(AF_INET,SOCK_STREAM,0))==-1){
    perror("create()");
    #ifdef TEST
        return 1; /* error */
    #endif
    exit(EXIT_FAILURE);
  }
  else{
  	#ifdef TEST
        return 0; /* success */
    #endif
    printf("Created tcp socket\n");
  }

 return 0;

}

/*Reusing ceated socket*/
int socket_reusing(){

 if (setsockopt(socket_tcp, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on)) < 0){
      perror("setsockopt()");
      exit(EXIT_FAILURE);
    }
  else{
    printf("Reusing socket\n");
  }
 
 return 0;

}

/*Binding socket to an adress*/
int socket_bind(){

  server.sin_family = AF_INET; //allways afinet if its tcp
  server.sin_port = htons(PORT); //host to network short 
  server.sin_addr.s_addr = INADDR_ANY; //assigning mine ip adess

//    #ifdef TEST
        int bind_out;
        bind_out = bind(socket_tcp, (struct sockaddr *)&server, sizeof(struct sockaddr));
        printf("bind result:%d\n", bind_out);
//    #endif
    
// if((bind(socket_tcp, (struct sockaddr *)&server, sizeof(struct sockaddr)))==-1){
   if(bind_out ==-1) {	
    perror("bind()");
    #ifdef TEST
        return 1; /* error */
    #endif
    exit(EXIT_FAILURE);
  }
  else{
  	#ifdef TEST
        return 0; /* success */
    #endif
    printf("Binding server socket\n");
  }

 return 0;
}

/*Listening for incomming connections*/
int socket_listening(){

 if((listen(socket_tcp, BACKLOG))<0){
    perror("listen()");
    #ifdef TEST
        return 1; /* error */
    #endif
    exit(EXIT_FAILURE);
  }
  else{
	#ifdef TEST
        return 0; /* success */
    #endif

    printf("Listening for connections\n");
  }

  return 0;
}



int new_socket_creation(){

  // remove if struct sockaddr_in client;  
 
 if(( new_socket = accept(socket_tcp, (struct sockaddr *)&client, &addrlen))==-1){
    perror("accept()");
    #ifdef TEST
        return 1; /* error */
    #endif
    exit(EXIT_FAILURE);
  }
  else{ 
  	#ifdef TEST
        return 0; /* success */
    #endif
    printf("Client IP is %s and port is : %d \n", inet_ntoa(client.sin_addr), ntohs(client.sin_port));
  }


  return 0;
}


/*Data exchage betwen other socket*/
int data_passing(){
 
 
  while(1){
    
    byte = recv(new_socket,reciv_data,BUFFER_SIZE,0);
    reciv_data[byte]= '\0';
    
    if (strcmp(reciv_data,"quit")==0){
      close(new_socket);
      printf("Closing server\n");
      break;	   
    } 
    else{
      printf("%s\n", reciv_data); 
      send(new_socket,reciv_data,strlen(reciv_data),0);


    }
  }
      close(socket_tcp);
   
      return 0;
   
}

   
