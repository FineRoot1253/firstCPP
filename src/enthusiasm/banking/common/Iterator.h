//
// Created by 홍준근 on 2023/02/07.
//

#ifndef FIRSTCPP_ITERATOR_H
#define FIRSTCPP_ITERATOR_H

#include "enthusiasm/banking/common/HGrowableList.h"

template <class T, class U>
class Iterator {
private:
    const U *currentData;
    int index;
public:
    explicit Iterator(const U *data) : currentData(data) {
        index = 0;
    }

    void First() {
        index = 0;
    }

    void Next() {
        index++;
    }

    bool IsDone() {
        return (index == currentData->getSize());
    }

    T Current() {
        return currentData->get(index);
    }
};

#endif //FIRSTCPP_ITERATOR_H
