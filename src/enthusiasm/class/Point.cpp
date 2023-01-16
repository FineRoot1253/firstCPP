//
// Created by 홍준근 on 2023/01/15.
//

#include "Point.h"

bool Point::init(int xpos, int ypos) {
    if (xpos < 0 || ypos < 0) {
        std::cout << "벗어난 범위의 값 전달" << std::endl;
        return false;
    }
    x = xpos;
    y = ypos;
    return true;
}

int Point::GetX() const {
    return x;
}

int Point::GetY() const {
    return y;
}

bool Point::SetX(int xpos) {
    if (xpos < 0 || xpos > 100) {
        std::cout << "벗어난 범위의 값 전달" << std::endl;
        return false;
    }
    x = xpos;
    return true;
}

bool Point::SetY(int ypos) {
    if (ypos < 0 || ypos > 100) {
        std::cout << "벗어난 범위의 값 전달" << std::endl;
        return false;
    }
    y = ypos;
    return true;
}
