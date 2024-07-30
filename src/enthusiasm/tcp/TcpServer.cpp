//
// Created by 홍준근 on 2024. 7. 30..
//


#include "TcpServer.h"
#include "enthusiasm/common/Error.h"

TcpServer::TcpServer(int portNumber) {
    std::memset(&address, 0, sizeof(address));
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = htonl(INADDR_ANY);
    address.sin_port = htons(portNumber);
    handleError(createSocket());
}

TcpServer::TcpServer(const TcpServer &ref) {
    std::memset(&address, 0, sizeof(address));
    address.sin_family = ref.address.sin_family;
    address.sin_addr.s_addr = ref.address.sin_addr.s_addr;
    address.sin_port = ref.address.sin_port;
    socket = ref.socket;
}

TcpServer::~TcpServer() {
    std::memset(&address, 0, sizeof(address));
    close(socket);
}

TcpServer &TcpServer::operator=(const TcpServer &ref) {
    std::memset(&address, 0, sizeof(address));
    address.sin_family = ref.address.sin_family;
    address.sin_addr.s_addr = ref.address.sin_addr.s_addr;
    address.sin_port = ref.address.sin_port;
    socket = ref.socket;
    return *this;
}


Error TcpServer::createSocket() {
    socket = ::socket(PF_INET, SOCK_STREAM, 0);
    if (socket < 0) {
        return Error{true, "socket() error"};
    }
    return Error{};
}

void TcpServer::handleError(const Error &error) {
    if (error.isError()) {
        fputs(error.getReason(), stderr);
        fputc('\n', stderr);
        exit(1);
    }
}

void TcpServer::bind() {
    if (::bind(socket, (struct sockaddr *) &address, sizeof(address)) == -1) {
        handleError(Error{true, "bind() error"});
    }
}

void TcpServer::listen() {
    if (::listen(socket, 5) == -1) {
        handleError(Error{true, "listen() error"});
    }
}

void TcpServer::accept(void (*hookFunction)(int)) {
    bind();
    listen();
    sockaddr_in clientAddress;
    socklen_t clientAddressSize = sizeof(clientAddress);
    while (true) {
        int clientSocket = ::accept(socket, (struct sockaddr *) &clientAddress, &clientAddressSize);
        if (clientSocket < 0) {
            handleError(Error{true, "acceptStart() Error"});
        }
        hookFunction(clientSocket);
    }
}

void TcpServer::acceptOnce(void (*hookFunction)(int)) {
    bind();
    listen();
    sockaddr_in clientAddress;
    socklen_t clientAddressSize = sizeof(clientAddress);
    int clientSocket = ::accept(socket, (struct sockaddr *) &clientAddress, &clientAddressSize);
    if (clientSocket < 0) {
        handleError(Error{true, "acceptStart() Error"});
    }
    hookFunction(clientSocket);
    close(socket);
    close(clientSocket);
}
