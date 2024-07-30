//
// Created by 홍준근 on 2024. 7. 30..
//
#include "enthusiasm/tcp/TcpServer.h"

void handleClient(int clientSocket) {
    const char* message = "Hello Client!";
    write(clientSocket, message, strlen(message));
    close(clientSocket);
}

int main(){
    TcpServer server = TcpServer(9999);
    server.acceptOnce(handleClient);
    return 0;
}