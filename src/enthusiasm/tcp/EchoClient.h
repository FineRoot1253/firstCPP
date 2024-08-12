//
// Created by 홍준근 on 2024. 8. 8..
//

#ifndef FIRSTCPP_ECHOCLIENT_H
#define FIRSTCPP_ECHOCLIENT_H

#include "enthusiasm/common/Error.h"
#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

class EchoClient {
private:
    int socket;
    sockaddr_in address;

private:
    Error createSocket();

public:
    EchoClient(const std::string& serverIp, int port);
    EchoClient(const EchoClient& ref);
    EchoClient(EchoClient&& ref) noexcept;
    EchoClient& operator=(const EchoClient& ref);
    EchoClient& operator=(EchoClient&& ref) noexcept;
    ~EchoClient();

public:
    void chat();
};


#endif //FIRSTCPP_ECHOCLIENT_H
