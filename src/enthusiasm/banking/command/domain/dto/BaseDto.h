//
// Created by 홍준근 on 2023/01/12.
//

#ifndef FIRSTCPP_ACCOUNTDTO_H
#define FIRSTCPP_ACCOUNTDTO_H
#include "enthusiasm/common/Error.h"
template <typename T>
struct BaseDto{
    T data;
    Error error;
};
#endif //FIRSTCPP_ACCOUNTDTO_H
