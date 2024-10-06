//socket
#include "socket_server.hpp"

using namespace std;

unsigned int Socket::startupServer(){
    //criando o windows meias
    //so repliquei a documentação fds
    WSADATA wsd;

    int started = WSAStartup(MAKEWORD(2, 2), &wsd);
    if(started != 0){
        cout << "O Winsock deu pau =C" << endl;
        return 1;
    }
    //criando o socket pra conectar agr
    Socket::server = socket(AF_INET, SOCK_STREAM, 0);
    if(Socket::server == INVALID_SOCKET){
        cout << "N deu pra criar socket" << endl;
        WSACleanup();
        return 1;
    }
    sockaddr_in serveraddress;
    serveraddress.sin_family = AF_INET;
    serveraddress.sin_addr.s_addr = INADDR_ANY;
    serveraddress.sin_port = htons(8080);

    if (bind(Socket::server, (sockaddr*)&serveraddress, sizeof(serveraddress)) == SOCKET_ERROR) {
        cout << WSAGetLastError() << endl;
        closesocket(server);
        WSACleanup();
        return 1;
    }
    if (listen(Socket::server, SOMAXCONN) == SOCKET_ERROR) {
        //cout << "teste";
        closesocket(server);
        WSACleanup();
        return 1;
    }

    cout << "Socket criado na porta localhost::8080" << endl;

}

unsigned int Socket::acceptConnection() {
    sockaddr_in clientaddress;
    int clientsize = sizeof(clientaddress);

    Socket::client = accept(Socket::server, (sockaddr*)&clientaddress, &clientsize);
    if (Socket::client == INVALID_SOCKET) {
        cout << "erro ao aceitar" << endl;
        closesocket(Socket::server);
        WSACleanup();
        return 1;
    }

    string handshake_response = 
        "HTTP/1.1 101 Switching Protocols\r\n"
        "Upgrade: websocket\r\n"
        "Connection: Upgrade\r\n"
        "Sec-WebSocket-Accept: dummy-key\r\n\r\n"; 

    send(Socket::client, handshake_response.c_str(), handshake_response.length(), 0);

    return 0;
}

unsigned int Socket::sendMessage(string message) {
    // Enviar uma mensagem de teste para o cliente
    string sentMessage = message;
    send(Socket::client, sentMessage.c_str(), sentMessage.length(), 0);

    return 0;
}

unsigned int Socket::receiveMessage(){

    char buffer[1024];
    int bytesReceived = recv(Socket::client, buffer, sizeof(buffer), 0);
    if (bytesReceived > 0) {
        cout << "Mensagem do html: " << string(buffer, bytesReceived) << endl;
    }

    return 0;
}

unsigned int Socket::stopServer(){
 closesocket(Socket::client);
 closesocket(Socket::server);
 WSACleanup();
}