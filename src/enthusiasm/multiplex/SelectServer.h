//
// Created by 홍준근 on 2024. 8. 8..
//

#ifndef FIRSTCPP_SELECTSERVER_H
#define FIRSTCPP_SELECTSERVER_H

#include <arpa/inet.h>
#include <sys/time.h>
#include <sys/select.h>
#include <iostream>

class SelectServer {
private:
    int serverSocket;
    int fdMax;
    sockaddr_in serverAddress;
    static const int BUF_SIZE = 100;
    timeval timeout;
    fd_set reads;
    fd_set readRef;
    const int port;

private:
    void socket();
    void bind();
    void initSelect();
    void acceptLoop();
    void select(int &fdNum);
    void parseFdSet();
    void parse(const int& fdIndex);
    void parseInternal(const int& fdIndex);
    void parseMsg(const int& fdIndex);

public:
    SelectServer(const int portNumber);
    SelectServer(const SelectServer& ref);
    SelectServer(SelectServer&& ref) noexcept;
    SelectServer& operator=(const SelectServer& ref);
    SelectServer& operator=(SelectServer&& ref) noexcept;
    ~SelectServer();

public:
    void listen();
};


#endif //FIRSTCPP_SELECTSERVER_H
