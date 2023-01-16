//
// Created by 홍준근 on 2023/01/16.
//

#ifndef FIRSTCPP_ENCAPS_2_H
#define FIRSTCPP_ENCAPS_2_H

#include <iostream>

class SinivelCap {
public:
    void take() const;
};

class SneezeCap{
public:
    void take() const;
};

class SnuffleCap{
public:
    void take() const;
};

class ConTac600{
private:
    SinivelCap sinivelCap;
    SneezeCap sneezeCap;
    SnuffleCap snuffleCap;
public:
    void take() const;
};

class ColdPatient{
public:
    void TakeConTac600(const ConTac600 &cap)const;
};
#endif //FIRSTCPP_ENCAPS_2_H