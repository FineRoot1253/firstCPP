//
// Created by 홍준근 on 2023/01/16.
//

#ifndef FIRSTCPP_ENCAPS_1_H
#define FIRSTCPP_ENCAPS_1_H

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

class ColdPatient{
public:
    void TakeSinivelCap(const SinivelCap &cap)const;
    void TakeSneezeCap(const SneezeCap &cap)const;
    void TakeSnuffleCap(const SnuffleCap &cap)const;
};


#endif //FIRSTCPP_ENCAPS_1_H
