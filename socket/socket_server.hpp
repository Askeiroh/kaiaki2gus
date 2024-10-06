//socket headers
/*
feito em colaboração com a documentação e tempo livre xisde
*/
#include <iostream>
#include <winsock2.h>
#include <ws2tcpip.h>

class Socket {
    private:
    SOCKET server;
    SOCKET client;
    public:
    unsigned int startupServer();
    unsigned int stopServer();
    unsigned int acceptConnection();
    unsigned int communicate();
};