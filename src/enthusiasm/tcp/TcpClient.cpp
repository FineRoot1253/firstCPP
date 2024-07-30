//
// Created by 홍준근 on 2024. 7. 30..
//

#include "TcpClient.h"

void TcpClient::handleError(Error error) {
    if (error.isError()) {
        fputs(error.getReason(), stderr);
        fputc('\n', stderr);
        exit(1);
    }
}

Error TcpClient::createSocket() {
    socket = ::socket(PF_INET, SOCK_STREAM, 0);
    if (socket < 0) {
        return Error{true, "socket() error"};
    }
    return Error{};
}

TcpClient::TcpClient(const std::string& serverIp, int port) {
    handleError(createSocket());
    memset(&address, 0, sizeof(address));
    address.sin_family=AF_INET;
    address.sin_port = htons(port);
    inet_pton(AF_INET, serverIp.c_str(), &address.sin_addr);
}

TcpClient::TcpClient(const TcpClient &ref) {
    handleError(createSocket());
    memcpy(&address, &ref.address, sizeof(address));
}


TcpClient::TcpClient(TcpClient&& ref) noexcept : socket(ref.socket), address(ref.address){
}

TcpClient& TcpClient::operator=(const TcpClient& ref){
    if(this != &ref){
        close(socket);
        handleError(createSocket());
        memcpy(&address, &ref.address, sizeof(address));
    }
    return *this;
}

TcpClient& TcpClient::operator=(TcpClient&& ref) noexcept{
    if(this != &ref){
        close(socket);
        handleError(createSocket());
        address = ref.address;
        socket = ref.socket;
        ref.socket = -1;
    }
    return *this;
}

TcpClient::~TcpClient(){
    close(socket);
}

void TcpClient::connect() {
    if(::connect(socket, (struct sockaddr*) (&address), sizeof(address)) == -1){
        handleError(Error{true, "connect() error"});
    }
    char messageBuffer[30];
    if(read(socket, messageBuffer, sizeof(messageBuffer)-1)==-1){
        handleError(Error{true, "read() error"});
    }
    printf("Message from server: %s \n", messageBuffer);
}
