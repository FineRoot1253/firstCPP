#include "enthusiasm/template/NonTypeTemplateParam.h"

int main(){
    SimpleArray<int, 5> integer5Array1;
    for (int i = 0; i <5 ; ++i) {
        integer5Array1[i] = i* 10;
    }

    SimpleArray<int, 5> integer5Array2;
    integer5Array2 = integer5Array1;
    for (int i = 0; i < 5; ++i) {
        std::cout<<integer5Array2[i]<<", ";
    }
    std::cout<<std::endl;

    SimpleArray<int, 7> integer7Array1;
    for (int i = 0; i < 7; ++i) {
        integer7Array1[i] = i* 10;
    }
    SimpleArray<int, 7> integer7Array2;
    integer7Array2 = integer7Array1;
    for (int i = 0; i < 7; ++i) {
        std::cout<<integer7Array2[i]<<", ";
    }
    std::cout<<std::endl;
    return 0;
}