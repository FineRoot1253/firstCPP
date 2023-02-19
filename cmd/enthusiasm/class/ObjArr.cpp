//
// Created by 홍준근 on 2023/01/16.
//

#include "enthusiasm/class/ObjArr.h"

int main(){
    Person personArr[3];
    char namestr[100];
    char *strptr;
    int age;
    int len;
    for (int i = 0; i < 3; ++i) {
        std::cout<<"이름: ";
        std::cin>>namestr;
        std::cout<<"나이: ";
        std::cin>>age;
        len = strlen(namestr)+1;
        strptr = new char[len];
        strcpy(strptr, namestr);
        personArr[i].setPersonInfo(strptr, age);
    }
    personArr[0].showPersonInfo();
    personArr[1].showPersonInfo();
    personArr[2].showPersonInfo();

    return 0;
}