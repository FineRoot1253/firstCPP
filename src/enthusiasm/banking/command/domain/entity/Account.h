//
// Created by 홍준근 on 2023/01/11.
//

#ifndef FIRSTCPP_ACCOUNT_H
#define FIRSTCPP_ACCOUNT_H

#include <iostream>

#include "enthusiasm/banking/command/domain/dto/BaseReturnDto.h"
#include "enthusiasm/banking/command/domain/dto/BalanceDto.h"
#include "enthusiasm/banking/common/equatable.h"

const int NAME_LEN = 20;

class Account: public Equatable<Account>{
private:
    long accId;
    int balance;
    char *cusName;
    Error deposit(int money);
    BaseReturnDto<int> withdraw(int money);
public:
    Account();
    Account(long accId, int balance, const char *cusName);
    Account(const Account& account);
    ~Account();

    long getAccId() const;

    int getBalance() const;

    char *getCusName() const;

    void showAccInfo() const;

    bool isEqual(const Account& other) const override;
    bool isNotEqual(const Account& other) const override;

    bool isEmpty() const;
    bool isNotEmpty() const;

    Error save(const BalanceDto& balanceDto);

    friend std::ostream & operator << (std::ostream &out,  const Account &account){
        out<<constants::txt_kr::TXT_INPUT_ACCOUNT_ID;
        out << account.accId << std::endl;
        out << constants::txt_kr::TXT_INPUT_CUSTOMER_NAME;
        out << account.cusName << std::endl;
        out<<constants::txt_kr::TXT_INPUT_LEFT;
        out << account.balance << std::endl;
        return out;
    };
};
#endif //FIRSTCPP_ACCOUNT_H
