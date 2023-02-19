//
// Created by 홍준근 on 2023/01/30.
//

#ifndef FIRSTCPP_ACCOUNTINPUTDTO_H
#define FIRSTCPP_ACCOUNTINPUTDTO_H

#include <iostream>
#include "enthusiasm/banking/common/BankingMode.h"
#include "enthusiasm/banking/common/constants.h"

class AccountInputDto{
private:
    long accountID;
    int money;
    char* customerName;

public:
    explicit AccountInputDto(long accountID = -1L,int money = 0, const char* customerName = "")
    : accountID(accountID)
    , money(money){
        this->customerName = new char[std::strlen(customerName)+1];
        std::strcpy(this->customerName,customerName);
    };


    ~AccountInputDto(){
        delete customerName;
    }

public:
    long getAccountID() const {
        return accountID;
    };

    int getMoney() const {
        return money;
    }

    const char* getCustomerName()const{
        return customerName;
    }

    friend std::istream & operator >> (std::istream &in,  AccountInputDto &accountInputDto){
        std::cout<<constants::txt_kr::TXT_INPUT_ACCOUNT_ID;

        in >> accountInputDto.accountID;
        std::cout<<constants::txt_kr::TXT_INPUT_CUSTOMER_NAME;
        in >> accountInputDto.customerName;
        std::cout<<constants::txt_kr::TXT_INPUT_DEPOSIT;
        in >> accountInputDto.money;
        return in;
    };
};
#endif //FIRSTCPP_ACCOUNTINPUTDTO_H
