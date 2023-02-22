//
// Created by 홍준근 on 2023/02/22.
//
#include <iostream>

void counter() {
    static int count;
    std::cout << "Current count: " << ++count << std::endl;
}

int main() {
    for (int i = 0; i < 10; ++i) {
        counter();
    }
    return 0;
}