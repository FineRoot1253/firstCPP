//
// Created by 홍준근 on 2024. 8. 8..
//

#ifndef FIRSTCPP_FDSERVERHANDLER_H
#define FIRSTCPP_FDSERVERHANDLER_H

#include <arpa/inet.h>
#include <sys/select.h>
#include <iostream>

namespace SocketHandler{
    namespace Select{
        void accept(const int& serverSocket, fd_set &reads, int& fdMax){
            sockaddr_in clientAddress;
            socklen_t  addressSize = sizeof(clientAddress);
            int clientSocket = ::accept(serverSocket, (struct sockaddr*) &clientAddress, &addressSize);
            FD_SET(clientSocket, &reads);
            if(fdMax < clientSocket){
                fdMax = clientSocket;
            }
            std::cout<<"connected client: "<<clientSocket<<std::endl;
        }
    }
}

#endif //FIRSTCPP_FDSERVERHANDLER_H
