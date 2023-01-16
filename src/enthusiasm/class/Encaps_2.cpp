//
// Created by 홍준근 on 2023/01/16.
//

#include "Encaps_2.h"

void SinivelCap::take() const {
    std::cout<<"콧물이 싸악~"<<std::endl;
}

void SneezeCap::take() const {
    std::cout<<"재채기가 낫습니다"<<std::endl;
}

void SnuffleCap::take() const {
    std::cout<<"코가 뻥 뚫립니다"<<std::endl;
}

void ConTac600::take() const {
    sinivelCap.take();
    sneezeCap.take();
    snuffleCap.take();
}

void ColdPatient::TakeConTac600(const ConTac600 &cap) const {
    cap.take();
}