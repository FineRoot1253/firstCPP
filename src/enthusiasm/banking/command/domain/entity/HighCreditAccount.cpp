//
// Created by 홍준근 on 2023/02/24.
//

#include "HighCreditAccount.h"
#include "enthusiasm/banking/common/utils.h"

Error HighCreditAccount::deposit(int money){
    const Error& defaultDepositResult = NormalAccount::deposit(money);

    if (defaultDepositResult.isError()) {
        return defaultDepositResult;
    }

    return Account::deposit(money * utils::getCreditRatio(creditGrade));
}