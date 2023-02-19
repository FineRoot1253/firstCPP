//
// Created by 홍준근 on 2023/02/02.
//

#ifndef FIRSTCPP_VIEWENTITYVALUE_H
#define FIRSTCPP_VIEWENTITYVALUE_H
#include "enthusiasm/banking/common/equatable.h"
#include <cstring>

class ViewEntityDefaultData:public Equatable<ViewEntityDefaultData> {
private:
    char *value;
public:
    ViewEntityDefaultData()
            : value(nullptr) {
        value = new char[std::strlen(constants::utils::TXT_DEFAULT)+1];
        std::strcpy(this->value, constants::utils::TXT_DEFAULT);
    };

    explicit ViewEntityDefaultData(const char* value){
        this->value = new char[std::strlen(value)+1];
        std::strcpy(this->value, value);
    };

    ViewEntityDefaultData(const ViewEntityDefaultData &viewEntityDefaultData):value(nullptr) {
        if(viewEntityDefaultData.value != nullptr){
            this->value = new char[std::strlen(viewEntityDefaultData.value)+1];
            std::strcpy(this->value, viewEntityDefaultData.value);
        }
    }

    ViewEntityDefaultData& operator=(const ViewEntityDefaultData &viewEntityDefaultData) {
        delete []value;
        this->value = new char[std::strlen(viewEntityDefaultData.value)+1];
        std::strcpy(this->value, viewEntityDefaultData.value);
        return *this;
    }

    ~ViewEntityDefaultData(){
        delete []value;
    }

    // strcmp는 같은 문자열일때 0을 반환한다. 하...
    bool isEqual(const ViewEntityDefaultData& other)const override {
        return !std::strcmp(this->value, other.value);
    }

    bool isNotEqual(const ViewEntityDefaultData& other)const override{
        return std::strcmp(this->value, other.value);
    }

    char* getValue() const { return value; }
};

#endif //FIRSTCPP_VIEWENTITYVALUE_H
