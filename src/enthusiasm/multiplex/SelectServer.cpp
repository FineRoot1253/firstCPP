//
// Created by 홍준근 on 2024. 8. 8..
//

#include <print>
#include "SelectServer.h"
#include "ExceptionHandler.h"
#include "FdServerHandler.h"


SelectServer::SelectServer(const int portNumber)
        : port(portNumber), serverSocket(-1) {

}

SelectServer::SelectServer(const SelectServer &ref)
        : port(ref.port), serverSocket(ref.serverSocket), fdMax(ref.fdMax) {
    if (this != &ref) {
        std::memcpy(&serverAddress, &ref.serverSocket, sizeof(serverAddress));
        std::memcpy(&reads, &ref.reads, sizeof(reads));
        std::memcpy(&readRef, &ref.readRef, sizeof(readRef));
        std::memcpy(&timeout, &ref.timeout, sizeof(timeout));
    }
}

SelectServer::SelectServer(SelectServer &&ref) noexcept
        : port(ref.port), serverSocket(ref.serverSocket), fdMax(ref.fdMax),
        serverAddress(ref.serverAddress), timeout(ref.timeout), reads(ref.reads), readRef(ref.readRef) {
    if (this != &ref) {
        ref.serverSocket = -1;
        ref.fdMax = 0;
        std::memset(&ref.serverAddress, 0, sizeof(ref.serverAddress));
        std::memset(&ref.timeout, 0, sizeof(ref.timeout));
        FD_ZERO(&ref.reads);
        FD_ZERO(&ref.readRef);
    }
}

SelectServer &SelectServer::operator=(const SelectServer &ref) {
    if (this != &ref) {
        serverSocket = ref.serverSocket;
        fdMax = ref.fdMax;
        std::memcpy(&serverAddress, &ref.serverSocket, sizeof(serverAddress));
        std::memcpy(&reads, &ref.reads, sizeof(reads));
        std::memcpy(&readRef, &ref.readRef, sizeof(readRef));
        std::memcpy(&timeout, &ref.timeout, sizeof(timeout));
    }
    return *this;
}

SelectServer &SelectServer::operator=(SelectServer &&ref) noexcept {
    if (this != &ref) {
        ref.serverSocket = -1;
        ref.fdMax = 0;
        std::memset(&ref.serverAddress, 0, sizeof(ref.serverAddress));
        std::memset(&ref.timeout, 0, sizeof(ref.timeout));
        FD_ZERO(&ref.reads);
        FD_ZERO(&ref.readRef);
    }
    return *this;
}

SelectServer::~SelectServer() {

}

void SelectServer::listen() {
    socket();
    bind();
    if (::listen(serverSocket, 5) == -1) {
        Exception::Handle::handleError(Error{true, "listen() error!"});
    }
    initSelect();
    acceptLoop();
}

void SelectServer::socket() {
    serverSocket = ::socket(PF_INET, SOCK_STREAM, 0);
    std::memset(&serverAddress, 0, sizeof(serverSocket));
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = htonl(INADDR_ANY);
    serverAddress.sin_port = htons(port);
}

void SelectServer::bind() {
    if (serverSocket < 0) {
        Exception::Handle::handleError(Error{true, "socket() not invoked yet!"});
    }
    if (::bind(serverSocket, (struct sockaddr *) &serverAddress, sizeof(serverAddress)) == -1) {
        Exception::Handle::handleError(Error{true, "bind() error!"});
    }
}

void SelectServer::initSelect() {
    FD_ZERO(&reads);
    FD_SET(serverSocket, &reads);
    fdMax = serverSocket;
}

void SelectServer::acceptLoop() {
    int flag = -2;
    while (true) {
        readRef = reads;
        timeout.tv_sec = 5;
        timeout.tv_usec = 0;
        select(flag);
        if (flag == 0) {
            continue;
        }
        parseFdSet();
    }
}

void SelectServer::select(int &fdNum) {
    if ((fdNum = ::select(fdMax + 1, &readRef, 0, 0, &timeout)) == -1) {
        Exception::Handle::handleError(Error{true, "select() error!"});
    }
}

void SelectServer::parseFdSet() {
    for (int i = 0; i < fdMax + 1; i++) {
        parse(i);
    }
}

void SelectServer::parse(const int &fdIndex) {
    if (FD_ISSET(fdIndex, &readRef)) {
        parseInternal(fdIndex);
    }
}

void SelectServer::parseInternal(const int &fdIndex) {
    if (fdIndex == serverSocket) {
        SocketHandler::Select::accept(serverSocket, reads, fdMax);
    } else {
        parseMsg(fdIndex);
    }

}

void SelectServer::parseMsg(const int &fdIndex) {
    char buf[BUF_SIZE];
    size_t strLen = read(fdIndex, buf, BUF_SIZE);
    if (strLen == 0) {
        FD_CLR(fdIndex, &reads);
        close(fdIndex);
        std::cout << "closed client: " << fdIndex << std::endl;
    } else {
        write(fdIndex, buf, strLen);
    }
}