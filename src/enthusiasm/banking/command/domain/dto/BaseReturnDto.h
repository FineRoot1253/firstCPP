//
// Created by 홍준근 on 2023/01/12.
//

#ifndef FIRSTCPP_ACCOUNTDTO_H
#define FIRSTCPP_ACCOUNTDTO_H
#include "enthusiasm/common/Error.h"

class Error;

template <typename T>
struct BaseReturnDto{
    T data;
    Error error;
};
#endif //FIRSTCPP_ACCOUNTDTO_H
