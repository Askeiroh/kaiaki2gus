#include <Windows.h> //arquivo fonte do windows, se for linux é bits/stdc++.h
#include "socket_server.hpp"

using namespace std; //standard, se nn por essa merda tem que ficar chamando o namespace antes das funções tipo: std::cout << "teste";, fica uma merda pra ler

//função main (raiz do programa) //teste
int main(){

  Socket servidorSocket;

  if(servidorSocket.startupServer() != 0){
    return 1;
  }

  if(servidorSocket.acceptConnection() != 0){
    return 1;
  }

  servidorSocket.sendMessage("Teste");
  servidorSocket.receiveMessage();
  servidorSocket.stopServer();
  return 0;
};
