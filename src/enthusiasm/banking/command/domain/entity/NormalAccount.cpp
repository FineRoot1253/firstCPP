//
// Created by 홍준근 on 2023/02/24.
//

#include "NormalAccount.h"

Error NormalAccount::deposit(int money) {
    const Error& defaultDepositResult = Account::deposit(money);
    if (defaultDepositResult.isError()) {
        return defaultDepositResult;
    }
    if (interestRatio > 0 ){
        return Account::deposit(money * (getInterestRatio() * 0.01));
    }
    return defaultDepositResult;
}

double NormalAccount::getInterestRatio() const {
    return interestRatio;
}