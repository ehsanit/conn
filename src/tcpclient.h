/**
 * Module:       tcpclient.h
 * Author(s):    Michal Musialik
 *
 * Description:  The typedef of the bitfield struct and
 *               all the prototypes for the functions used
 *               by tcpclent.h
 *
 */


int socket_host(char *argv[]);
int socket_create(void);
int socket_binding(void);
int socket_connection(char *argv[]);
int data_passing(void);
