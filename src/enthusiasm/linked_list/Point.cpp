//
// Created by 홍준근 on 2023/03/18.
//

#include "Point.h"

Point::Point(const int &xpos, const int &ypos)
        : xpos(xpos)
          , ypos(ypos) {
}

Point::Point(const Point &ref)
        : xpos(ref.xpos)
          , ypos(ref.ypos) {
}

Point &Point::operator=(const Point &ref) {
    xpos = ref.xpos;
    ypos = ref.ypos;
    return *this;
}

bool Point::isXposEqual(const Point &target) {
        if(this->xpos == target.xpos){
            return true;
        }
        return false;
    }

bool Point::isYposEqual(const Point &target) {
        if(this->ypos == target.ypos){
            return true;
        }
        return false;
    }

int Point::getXpos() const {
    return xpos;
}

int Point::getYpos() const {
    return ypos;
}

void Point::showPointPosition() const {
    std::cout << "[" << xpos << ", " << ypos << "]" << std::endl;
}

int Point::compareWith(const Point &target) {
    if(this->xpos == target.xpos && this->ypos == target.ypos){
        return 0;
    }else if(isXposEqual(target)){
        return 1;
    }else if(isYposEqual(target)){
        return 2;
    }
    return -1;
}



