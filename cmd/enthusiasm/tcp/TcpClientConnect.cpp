//
// Created by 홍준근 on 2024. 7. 30..
//

#include "enthusiasm/tcp/TcpClient.h"

int main(){
    TcpClient client = TcpClient("127.0.0.1", 9999);
    client.connect();
    return 0;
}