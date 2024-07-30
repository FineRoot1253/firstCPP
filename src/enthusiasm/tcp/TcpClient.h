//
// Created by 홍준근 on 2024. 7. 30..
//

#ifndef FIRSTCPP_TCPCLIENT_H
#define FIRSTCPP_TCPCLIENT_H

#include "enthusiasm/common/Error.h"
#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

class TcpClient {
private:
    int socket;
    sockaddr_in address;

private:
    void handleError(Error error);
    Error createSocket();

public:
    TcpClient(const std::string& serverIp, int port);
    TcpClient(const TcpClient& ref);
    TcpClient(TcpClient&& ref) noexcept;
    TcpClient& operator=(const TcpClient& ref);
    TcpClient& operator=(TcpClient&& ref) noexcept;
    ~TcpClient();

public:
    void connect();
};


#endif //FIRSTCPP_TCPCLIENT_H
