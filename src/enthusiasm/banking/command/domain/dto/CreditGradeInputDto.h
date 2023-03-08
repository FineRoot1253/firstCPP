//
// Created by 홍준근 on 2023/02/26.
//

#ifndef FIRSTCPP_CREDITGRADEINPUTDTO_H
#define FIRSTCPP_CREDITGRADEINPUTDTO_H
#include "enthusiasm/banking/common/Exception.h"
#include <iostream>

class CreditGradeInputDto {
private:
    int value;
public:
    CreditGradeInputDto(const int& value){
        if (value <= 0 || value >= 4){ // 1 ~ 3
            throw AccountSystemException(constants::ex_kr::EX_MSG_SYS_ILLEGAL_INPUT);
        }
        this->value = value;
    };

    friend std::istream & operator >> (std::istream &in, CreditGradeInputDto &creditGradeInputDto){
        std::cout<<constants::txt_kr::TXT_INPUT_CREDIT_GRADE;
        in>>creditGradeInputDto.value;
        return in;
    };

    int getValue() const{
        return value;
    };
};
#endif //FIRSTCPP_CREDITGRADEINPUTDTO_H
