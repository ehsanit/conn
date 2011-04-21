/**
 * Module:       tcpserver.h
 * Author(s):    Michal Musialik
 *
 * Description:  The typedef of the bitfield struct and
 *               all the prototypes for the functions used
 *               by tcpserver.h
 *
 */

void host_setup(void);
int socket_create(void);
int socket_reusing(void);
int socket_bind(void);
int socket_listening(void);
int new_socket_creation(void);
void data_passing(void);
