#ifndef __NET_H__
#define __NET_H__
#include "common.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>

//Generated with genfile -d net.h -i "['common.h']"



struct y_socket {
	struct addrinfo * hints;
	struct addrinfo *res;
	struct addrinfo *p;
	int sockfd;
};

typedef struct y_socket y_socket;

struct y_server {
	y_socket socket;
};

typedef struct y_server y_server;

struct y_client {
	y_socket socket;
};

typedef struct y_client y_client;

int y_server_start(y_server * server);
//! \fn y_server_start(y_server * server);
//! \brief create a server
//! \param callback callback to use to process information

int y_server_stop(y_server * server);
//! \fn y_server_stop(y_server * server)
//! \brief stop a running server
//! \param server the server to stop

int y_connect(y_socket * socket);
//! \fn y_connect()
//! \brief connect to a remote server
//! \param socket the socket to connect to
//! \param
int y_disconnect(y_socket * socket);
//! \fn y_disconnect()
//! \brief disconnect from remote server
//! \param socket the socket to connect to 

#endif //__NET_H__
