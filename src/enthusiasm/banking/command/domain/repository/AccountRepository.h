//
// Created by 홍준근 on 2023/01/11.
//

#ifndef FIRSTCPP_ACCOUNTREPOSITORY_H
#define FIRSTCPP_ACCOUNTREPOSITORY_H

#include "enthusiasm/banking/command/domain/entity/Account.h"
#include "enthusiasm/banking/command/domain/dto/BaseReturnDto.h"
#include "enthusiasm/banking/common/HGrowableList.h"
#include "enthusiasm/banking/command/domain/dto/AccountInputDto.h"

class AccountRepository {
private:
    HGrowableList<Account*> accList;
    int accNum = 0;
public:
    AccountRepository();
//    AccountRepository(Account* const**accArr, const int &accNum);
    AccountRepository(const AccountRepository& accountRepository);

    BaseReturnDto<Account*> findById(const long& accId) const;
    const HGrowableList<Account*>& findAll() const;
    BaseReturnDto<int> getTotalCounts() const;

    Error saveAccount(const AccountInputDto& accountInputDto);

    Error saveBalance(const BalanceDto& balanceDto);
};

#endif //FIRSTCPP_ACCOUNTREPOSITORY_H
