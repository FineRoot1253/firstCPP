//
// Created by 홍준근 on 2023/02/01.
//

#ifndef FIRSTCPP_VIEWID_H
#define FIRSTCPP_VIEWID_H

#include "enthusiasm/banking/common/equatable.h"

class ViewID: public Equatable<ViewID>{
private:
    long value;
public:
    ViewID():value(-1L){};
    explicit ViewID(const long& value):value(value){};
    ViewID(const ViewID& viewId):value(viewId.value){};
    ViewID& operator=(const ViewID& ref){
        this->value=ref.value;
        return *this;
    }

    bool isEqual(const ViewID& other) const override{
        return other.value == value;
    };
    bool isNotEqual(const ViewID& other) const override{
        return other.value != value;
    };

    const long &getValue() const{
        return value;
    };
};
#endif //FIRSTCPP_VIEWID_H
