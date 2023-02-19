//
// Created by 홍준근 on 2023/01/30.
//

#ifndef FIRSTCPP_MONEY_H
#define FIRSTCPP_MONEY_H

#include <iostream>
#include "enthusiasm/banking/common/BankingMode.h"
#include "enthusiasm/banking/common/constants.h"

class MoneyInputDto {
private:
    long accountID;
    int money;
    eBankingMode mode;

private:
    const char *getRequireInputMoneyText() {
        if (mode == eBankingMode::Deposit) {
            return constants::txt_kr::TXT_INPUT_DEPOSIT;
        }
        return constants::txt_kr::TXT_INPUT_WITHDRAW;
    }

public:
     explicit MoneyInputDto(long accountID = -1L, int money = 0, eBankingMode mode = eBankingMode::Deposit)
            : accountID(accountID)
              , money(money)
              , mode(mode) {
    };

    explicit MoneyInputDto(eBankingMode mode)
            : accountID(-1L)
              , money(0)
              , mode(mode) {
    };

public:
    long getAccountID() const {
        return accountID;
    };

    int getMoney() const {
        return money;
    }

    friend std::istream &operator>>(std::istream &in, MoneyInputDto &moneyInputDto) {
        std::cout << constants::txt_kr::TXT_INPUT_ACCOUNT_ID;
        in >> moneyInputDto.accountID;
        std::cout << moneyInputDto.getRequireInputMoneyText();
        in >> moneyInputDto.money;
        return in;
    };
};

#endif //FIRSTCPP_MONEY_H
