//
// Created by 홍준근 on 2023/01/31.
//

#ifndef FIRSTCPP_EQUATABLE_H
#define FIRSTCPP_EQUATABLE_H

//#include "enthusiasm/banking/common/ViewEntitySet.h"
//#include "enthusiasm/banking/common/ViewEntityDefaultData.h"

template<class T>
class Equatable {
    virtual bool isEqual(const T &other) const = 0;

    virtual bool isNotEqual(const T &other) const = 0;
};

#endif //FIRSTCPP_EQUATABLE_H
