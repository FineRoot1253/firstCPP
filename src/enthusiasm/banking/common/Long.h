//
// Created by 홍준근 on 2023/01/31.
//

#ifndef FIRSTCPP_LONG_H
#define FIRSTCPP_LONG_H

#include "enthusiasm/banking/common/equatable.h"

class Long : public Equatable<Long> {
private:
    long value;
public:
    Long(const long &value) : value(value) {
    }

    const long &getValue() const {
        return value;
    };

    bool isEqual(const Long &other) const override {
        return value == other.getValue();
    };

    bool isNotEqual(const Long &other) const override {
        return value != other.getValue();
    };
};

#endif //FIRSTCPP_LONG_H
