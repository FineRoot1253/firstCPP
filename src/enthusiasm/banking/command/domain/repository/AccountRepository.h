//
// Created by 홍준근 on 2023/01/11.
//

#ifndef FIRSTCPP_ACCOUNTREPOSITORY_H
#define FIRSTCPP_ACCOUNTREPOSITORY_H

#include "enthusiasm/common/Account.h"
#include "enthusiasm/banking/command/domain/dto/BaseDto.h"

class AccountRepository {
private:
    Account accArr[100];
    int accNum = 0;
public:
    AccountRepository(const Account accArr[100], const int &accNum);
    BaseDto<Account> findById(const long accId);
    Account* findAll();
    BaseDto<int> getTotalCounts();

    Error saveAccount(Account account);

    Error saveBalance(Account account);
};

#endif //FIRSTCPP_ACCOUNTREPOSITORY_H
