//
// Created by 홍준근 on 2023/01/16.
//

#ifndef FIRSTCPP_BALANCEDTO_H
#define FIRSTCPP_BALANCEDTO_H

#include <iostream>
#include "enthusiasm/banking/common/BankingMode.h"

class BalanceDto{
private:
    long accId;
    int balance;
    eBankingMode bankingMode;
public:
    explicit BalanceDto(const long& accId = -1L, const int& balance =0 ,const eBankingMode& bankingMode = eBankingMode::Deposit)
    : accId(accId)
    , balance(balance)
    , bankingMode(bankingMode){
    };
    long getAccId() const {
        return accId;
    }

    eBankingMode getCurrentMode() const {
        return bankingMode;
    }

    int getBalance() const {
        return balance;
    }

};
#endif //FIRSTCPP_BALANCEDTO_H
