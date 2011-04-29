
/*Author Michal Musialik*/

#define PORT 9600 // port macro
#define BUFFER_SIZE 32 // message buffer size

int socket_tcp; // tcp_socket name
char send_data[BUFFER_SIZE];

struct sockaddr_in connecting; 
struct hostent * host; //Host adress




int socket_create(){

 if((socket_tcp = socket(AF_INET, SOCK_STREAM,0))==-1){
     printf("failed to create a socket\n");
     exit(EXIT_FAILURE);
   }
 else{
     printf("socket is succesfully created\n");
   
   }
 return 0;
}



int socket_binding(){

  host = (struct hostent *)gethostbyname((char *)"129.16.79.137");
  connecting.sin_family = AF_INET;
  connecting.sin_port = htons(PORT); //my port here
  connecting.sin_addr= *((struct in_addr *)host->h_addr);
  memset(&(connecting.sin_zero),'\0',8);

 return 0;
}

int socket_connection(){


 if(connect(socket_tcp,(struct sockaddr *)&connecting,sizeof(struct sockaddr))==-1)
  {
    perror("connect()");
    exit(1);
  }
 else{
      printf("Client is connected\n");
 }

 return 0;
}


void send_up (void){
  printf("Sending up\n");
  send(socket_tcp,"10",2,0);
  
}

void send_down (void){
 printf("Sending down\n"); 
 send(socket_tcp,"5",2,0);
  
}

void send_left (void){
 printf("Sending left\n");
  send(socket_tcp,"12",2,0);
  
}

void send_right (void){
 printf("Sending right\n");
  send(socket_tcp,"3",2,0);
  
}

void send_exit(void){
 printf("shutting\n");
  send(socket_tcp,"quit",4,0);
  close(socket_tcp);
}
