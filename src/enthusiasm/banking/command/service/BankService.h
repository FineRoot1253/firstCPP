//
// Created by 홍준근 on 2023/01/11.
//

#ifndef FIRSTCPP_BANKSERVICE_H
#define FIRSTCPP_BANKSERVICE_H

#include "enthusiasm/banking/command/domain/repository/AccountRepository.h"

class BankService {
private:
    AccountRepository* accountRepository;
public:
    BankService(AccountRepository accountRepository);
    ~BankService();

    Error makeAccount(const Account account);
    Error  depositMoney(const long accId, const int money);
    Error withdrawMoney(const long accId, const int money);
    Account* findAll();
};


#endif //FIRSTCPP_BANKSERVICE_H
