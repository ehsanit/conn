#include "ui_mask.c"
/*Author michal musialik*/

#define UP_STATE 0
#define DOWN_STATE 0
#define LEFT_STATE 0
#define RIGHT_STATE 0
#define ALT_UP_STATE 0
#define ALT_DOWN_STATE 0

#define IP_BUFFER_LENGTH 200
#define PORT 9600 // port macro
#define BUFFER_SIZE 32 // message buffer size
#define BACKLOG 5 //Number of socket connection aviable in listen

int socket_tcp; // tcp_socket name
int new_socket;//name of incomming socket
int receive; // receive value
int sending; //sending value
int addrlen; // length of an adress
int on = 1;//setcokopt option_value argument
char ip_buffer[IP_BUFFER_LENGTH];//buffer for ip
char reciv_data[BUFFER_SIZE]; // buffer for message length


struct sockaddr_in server;

int temp;//variable for parsing from string to int 


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

int socket_create(){

 if(( socket_tcp = socket(AF_INET,SOCK_STREAM,0))==-1){
    perror("create()");
    exit(EXIT_FAILURE);
  }
  else{
    printf("Created tcp socket\n");
  }

 return 0;

}

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

int socket_binding(){

  server.sin_family = AF_INET; //allways afinet if its tcp
  server.sin_port = htons(PORT); //host to network short 
  server.sin_addr.s_addr = INADDR_ANY; //assigning mine ip adess

 if((bind(socket_tcp, (struct sockaddr *)&server, sizeof(struct sockaddr)))==-1){  
    perror("bind()");
    exit(EXIT_FAILURE);
  }
  else{
    printf("Binding server socket\n");
  }

 return 0;
}

int socket_listening(){

 if((listen(socket_tcp, BACKLOG))<0){
    perror("listen()");
    exit(EXIT_FAILURE);
  }
  else{
    printf("Listening for connections\n");
  }

  return 0;
}



int new_socket_creation(){

struct sockaddr_in client;  
 
 if(( new_socket = accept(socket_tcp, (struct sockaddr *)&client, &addrlen))==-1){
    perror("accept()");
    exit(EXIT_FAILURE);
  }
  else{ 
    printf("Client IP is %s and port is : %d \n", inet_ntoa(client.sin_addr), ntohs(client.sin_port));
  }


  return 0;
}



int data_passing(void){
 
 
  while(1){
    receive = recv(new_socket,reciv_data,BUFFER_SIZE,0);
    
     reciv_data[receive]= '\0';
    
    if (strcmp(reciv_data,"quit")==0){
      close(new_socket);
      printf("Closing server\n");
      break;	   
    } 
    else{
      printf("%s\n", reciv_data); 
      temp = atoi(reciv_data);
      controll_movement(temp);
    }
  }
      close(socket_tcp);  
   
 
      return 0;
   
}

   
