//
// Created by 홍준근 on 2023/02/25.
//

#ifndef FIRSTCPP_ACCOUNTTYPEINPUTDTO_H
#define FIRSTCPP_ACCOUNTTYPEINPUTDTO_H
#include <iostream>
#include "enthusiasm/banking/common/Exception.h"
#include "enthusiasm/banking/common/AccountType.h"

class AccountTypeInputDto{
private:
    int value;
public:
    explicit AccountTypeInputDto(const int& value){
        if (value <= 0 ||value >= 3){ // 1 or 2
            throw AccountSystemException(constants::ex_kr::EX_MSG_SYS_ILLEGAL_INPUT);
        }
        this->value = value;
    };

    friend std::istream & operator >> (std::istream &in, AccountTypeInputDto &accountType){
        std::cout<<constants::txt_kr::TXT_INPUT_ACCOUNT_TYPE_TITLE<<std::endl;
        std::cout<<constants::txt_kr::TXT_INPUT_ACCOUNT_TYPE<<std::endl;
        in>>accountType.value;
        return in;
    };

    AccountType toAccountType() const {
        switch(value){
            case 1:
                return AccountType::NORMAL;
            default:
                return AccountType::HIGH_CREDIT;
        }
    }

};
#endif //FIRSTCPP_ACCOUNTTYPEINPUTDTO_H
