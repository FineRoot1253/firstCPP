//
// Created by 홍준근 on 2023/01/16.
//

#include "Encaps_1.h"

void SinivelCap::take() const {
    std::cout<<"콧물이 싸악~"<<std::endl;
}

void SneezeCap::take() const {
    std::cout<<"재채기가 낫습니다"<<std::endl;
}

void SnuffleCap::take() const {
    std::cout<<"코가 뻥 뚫립니다"<<std::endl;
}

void ColdPatient::TakeSinivelCap(const SinivelCap &cap) const {
    cap.take();
}

void ColdPatient::TakeSneezeCap(const SneezeCap &cap) const {
    cap.take();
}

void ColdPatient::TakeSnuffleCap(const SnuffleCap &cap) const {
    cap.take();
}