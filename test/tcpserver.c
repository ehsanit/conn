#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <string.h>
#include "state.h" 

#define IP_BUFFER_LENGTH 200
#define PORT 9600 // port macro
#define BUFFER_SIZE 1024 // message buffer size
#define LOGIN "admin" //Login
#define BACKLOG 5 //Number of socket connection aviable in listen

/*you run it by adding admin argument*/
/*by michal musialik*/

/*You run the software with admin argument*/

int main(int argc, char **argv){
  
  struct sockaddr_in sin;
  //struct sockaddr_in client;/* will be activated in upcomming version*/
  
  int socket_bind; //bound socket value
  int sending; //sending value
  int receive; // receive value
  int addrlen; // length of an adress
  int new_socket;//number of ip adress
  int socket_tcp; // tcp_socket name
  char ip_buffer[200];//buffer for ip
  char *buffer=malloc(BUFFER_SIZE); // buffer for message length
  char welcome_message [BUFFER_SIZE] = "Welcome to the jungle!!!";

  /*check if the correct login is provided*/  
   if(strcmp(argv[1],LOGIN) != 0){
      printf("Access denied\n");
      exit(EXIT_SUCCESS);
    }
   else{
     
     /*gathering information about current server*/
     struct hostent * Host ;
     gethostname(ip_buffer , IP_BUFFER_LENGTH);
     printf("%s\n", ip_buffer);
     Host = ( struct hostent * )gethostbyname(ip_buffer);
     printf("Host name : %s\n", Host->h_name) ;
     printf("Host IP Address : %s\n", inet_ntoa(*((struct in_addr *)Host->h_addr)));
   

     /*Creating a tcp socket and checking if the socket is created suceffuly*/
    socket_tcp = socket(AF_INET,SOCK_STREAM,0);
   if (socket_tcp == -1){
       perror("Create socket \n");
     }
   else{
       printf("Created tcp socket\n");
     }

   /*socket adress struct*/

   sin.sin_family = AF_INET; //allways afinet if its tcp
   sin.sin_port = htons(PORT); //host to network short 
   sin.sin_addr.s_addr = INADDR_ANY; //assigning mine ip adess
   
   /*binding socket to an adress and doing check if you can bind it*/
   
   socket_bind = bind(socket_tcp, (struct sockaddr *)&sin, sizeof(struct sockaddr));
   if(socket_bind < 0){
       perror("Cannot bind socket\n");
       exit(EXIT_FAILURE);
     }
   else{
       printf("binding server socket\n");
     }
   /*listen for other sockets*/
   /*listning for a socket name and how many connection are pending*/
   
   listen(socket_tcp, BACKLOG);

    /*accepting connection*/
   
   addrlen = sizeof(struct sockaddr);
   /*creating new socket and checking if the socket can be created*/
   new_socket = accept(socket_tcp, (struct sockaddr *)&sin, &addrlen);
   
   if(new_socket < 0){
       perror("accepting socket error");
       exit(EXIT_FAILURE);
     }
   else{ 
       printf("Welcome to ser mrs ALI\n");
       printf("new socket with adress %d\n", new_socket);
       
     }

   /*new socket and check if it accepted corectly*/
   receive = recv(new_socket,buffer,BUFFER_SIZE-1,0);
    
   if(receive < 0){
       printf("Cannot receive massage");
       exit(EXIT_FAILURE);
     }
   else{
     /*printing in message send from the client*/
     buffer[BUFFER_SIZE]= '\0';
     printf("%s\n", buffer);
     /*simulation of states comming from camera module*/
     if(strcmp(buffer,"state")==0){
       printf("the state %d\n", check());
       }

     }

  
   /*sending test to the lient as a confirmation*/
   sending = send(new_socket, welcome_message,sizeof(welcome_message),0);
   
   if(sending < 0){
       perror("Cant send Welcome message\n");
       exit(EXIT_FAILURE);
     }
   else{
       printf("data send %s\n", welcome_message);
       printf("buffer size send %i\n",sizeof(welcome_message));
     }
 
   
   free(buffer);  
   
   /*closing sockets*/
   close(new_socket);
   close(socket_tcp);   
   exit(EXIT_SUCCESS);
   return 0;
     }

}
