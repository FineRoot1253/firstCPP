#include <iostream>

int main(){
    int num = 0x010203;
    char * str = reinterpret_cast<char*>(&num);

    for (int i = 0; i < sizeof(num); ++i) {
        std::cout<<static_cast<int>(*(str+i))<<std::endl;
    }

    return 0;
}


