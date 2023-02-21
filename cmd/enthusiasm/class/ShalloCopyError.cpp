//
// Created by 홍준근 on 2023/02/19.
//

#include "enthusiasm/class/ShalloCopyError.h"

int main(){
    Person man1("Lee dong woo", 29);
    Person man2=man1;
    man1.showPersonInfo();
    man2.showPersonInfo();
    return 0;
}