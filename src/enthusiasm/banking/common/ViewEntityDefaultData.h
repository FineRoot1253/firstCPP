//
// Created by 홍준근 on 2023/02/02.
//

#ifndef FIRSTCPP_VIEWENTITYVALUE_H
#define FIRSTCPP_VIEWENTITYVALUE_H
#include "enthusiasm/banking/common/equatable.h"
#include <string>

class ViewEntityDefaultData:public Equatable<ViewEntityDefaultData> {
private:
    std::string value;
public:
    ViewEntityDefaultData()
            : value(std::string()) {
    };

    explicit ViewEntityDefaultData(const std::string& value): value(value){
    };

    ViewEntityDefaultData(const ViewEntityDefaultData &viewEntityDefaultData):value(viewEntityDefaultData.value) {
    }

    ViewEntityDefaultData& operator=(const ViewEntityDefaultData &viewEntityDefaultData) {
        value = viewEntityDefaultData.value;
        return *this;
    }

    ~ViewEntityDefaultData(){
    }

    // strcmp는 같은 문자열일때 0을 반환한다. 하...
    bool isEqual(const ViewEntityDefaultData& other)const override {
        return !value.compare(other.value);
    }

    bool isNotEqual(const ViewEntityDefaultData& other)const override{
        return value.compare(other.value);
    }

    std::string getValue() const { return value; }
};

#endif //FIRSTCPP_VIEWENTITYVALUE_H
