//
// Created by 홍준근 on 2024. 8. 8..
//

#include "enthusiasm/multiplex/SelectServer.h"

int main(){
    SelectServer server = SelectServer(19999);
    server.listen();
    return 0;
}