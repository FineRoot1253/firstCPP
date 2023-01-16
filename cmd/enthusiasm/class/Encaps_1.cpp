//
// Created by 홍준근 on 2023/01/16.
//
#include "enthusiasm/class/Encaps_1.h"

int main(){
    SinivelCap sinivelCap;
    SneezeCap sneezeCap;
    SnuffleCap snuffleCap;

    ColdPatient sufferer;
    sufferer.TakeSinivelCap(sinivelCap);
    sufferer.TakeSneezeCap(sneezeCap);
    sufferer.TakeSnuffleCap(snuffleCap);
    return 0;
}