//
// Created by 홍준근 on 2024. 8. 8..
//

#include "enthusiasm/tcp/EchoClient.h"

int main(){
    EchoClient echoClient = EchoClient("127.0.0.1", 19999);
    echoClient.chat();
    return 0;
}