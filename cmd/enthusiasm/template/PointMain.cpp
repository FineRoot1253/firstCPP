//
// Created by 홍준근 on 2023/02/23.
//

#include "enthusiasm/template/PointTemplate.h"

int main(){
    Point<int> pos1(3, 4);
    pos1.showPosition();

    Point<double> pos2(2.4, 3.6);
    pos2.showPosition();

    Point<char> pos3('P', 'F');
    pos3.showPosition();
    return 0;
}