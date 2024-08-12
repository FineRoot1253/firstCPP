//
// Created by 홍준근 on 2024. 8. 8..
//

#include "EchoClient.h"
#include "ExceptionHandler.h"

Error EchoClient::createSocket() {
    socket = ::socket(PF_INET, SOCK_STREAM, 0);
    if (socket < 0) {
        return Error{true, "socket() error"};
    }
    return Error{};
}

EchoClient::EchoClient(const std::string& serverIp, int port) {
    Exception::Handle::handleError(createSocket());
    memset(&address, 0, sizeof(address));
    address.sin_family=AF_INET;
    address.sin_port = htons(port);
    inet_pton(AF_INET, serverIp.c_str(), &address.sin_addr);
}

EchoClient::EchoClient(const EchoClient &ref) {
    Exception::Handle::handleError(createSocket());
    std::memcpy(&address, &ref.address, sizeof(address));
}


EchoClient::EchoClient(EchoClient&& ref) noexcept : socket(ref.socket), address(ref.address){
}

EchoClient& EchoClient::operator=(const EchoClient& ref){
    if(this != &ref){
        close(socket);
        Exception::Handle::handleError(createSocket());
        memcpy(&address, &ref.address, sizeof(address));
    }
    return *this;
}

EchoClient& EchoClient::operator=(EchoClient&& ref) noexcept{
    if(this != &ref){
        close(socket);
        Exception::Handle::handleError(createSocket());
        address = ref.address;
        socket = ref.socket;
        ref.socket = -1;
    }
    return *this;
}

EchoClient::~EchoClient(){
    close(socket);
}

/** chat()
 * 동기식 채팅 시작
 * @return void
 */
void EchoClient::chat(){
    if(::connect(socket, (struct sockaddr*) (&address), sizeof(address)) == -1){
        Exception::Handle::handleError(Error{true, "connect() error"});
    }
    char buffer[1024];
    while(true){
        std::cout<<"Input message(Q to quit): ";
        std::cin>>buffer;
        if(!std::strcmp(buffer, "q\n") || !std::strcmp(buffer, "Q\n") ){
            break;
        }
        write(socket, buffer, std::strlen(buffer));
        size_t strLen = read(socket, buffer, 1023);
        buffer[strLen] = 0;
        std::cout<<"Message from server: "<<buffer<<std::endl;
    }
}