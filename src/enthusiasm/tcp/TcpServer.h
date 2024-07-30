//
// Created by 홍준근 on 2024. 7. 30..
//

#ifndef FIRSTCPP_TCPSERVER_H
#define FIRSTCPP_TCPSERVER_H

#include <arpa/inet.h>
#include <sys/socket.h>
#include <cstdio>
#include <cstdlib>
#include <unistd.h>
#include "enthusiasm/common/Error.h"

class TcpServer {
private:
    sockaddr_in address;
    int socket;

private:
    Error createSocket();
    void handleError(const Error& error);
    void bind();
    void listen();

public:
    TcpServer(int portNumber);
    TcpServer(const TcpServer& ref);
    ~TcpServer();
    TcpServer& operator=(const TcpServer& ref);

public:
    void accept(void (*hookFunction)(int));
    void acceptOnce(void (*hookFunction)(int));
};


#endif //FIRSTCPP_TCPSERVER_H
