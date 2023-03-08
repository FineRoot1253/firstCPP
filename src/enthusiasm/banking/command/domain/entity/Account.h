//
// Created by 홍준근 on 2023/01/11.
//

#ifndef FIRSTCPP_ACCOUNT_H
#define FIRSTCPP_ACCOUNT_H

#include <iostream>

#include "enthusiasm/banking/command/domain/dto/BaseReturnDto.h"
#include "enthusiasm/banking/command/domain/dto/BalanceDto.h"
#include "enthusiasm/banking/common/equatable.h"
#include "enthusiasm/banking/command/domain/dto/AccountInputDto.h"

const int NAME_LEN = 20;

class Account: public Equatable<Account>{
private:
    long accId;
    int balance;
    std::string cusName;
    virtual BaseReturnDto<int> withdraw(int money);
protected:
    virtual Error deposit(int money);
public:
    Account();
    Account(long accId, int balance, std::string cusName);
    Account(const Account& account);
    virtual ~Account();

    virtual long getAccId() const;

    virtual int getBalance() const;

    virtual  std::string getCusName() const;

    void showAccInfo() const;

    bool isEqual(const Account& other) const override;
    bool isNotEqual(const Account& other) const override;

    bool isEmpty() const;
    bool isNotEmpty() const;

    virtual Error save(const BalanceDto& balanceDto);

    virtual std::ostream& format(std::ostream& out) const = 0;

    friend std::ostream & operator << (std::ostream &out,  const Account &account){
        return account.format(out);
    }
};
#endif //FIRSTCPP_ACCOUNT_H
