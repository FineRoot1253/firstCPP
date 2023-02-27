//
// Created by 홍준근 on 2023/02/27.
//

#ifndef FIRSTCPP_ACCOUNTFACTORY_H
#define FIRSTCPP_ACCOUNTFACTORY_H
#include "Account.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"
#include "enthusiasm/banking/command/domain/dto/AccountInputDto.h"

class AccountFactory{
public:
    Account* createAccount(const AccountInputDto& accountInputDto){
        switch(accountInputDto.getAccountType()){
            case AccountType::NORMAL:
                return new NormalAccount(accountInputDto);
            default:
                return new HighCreditAccount(accountInputDto);
        }
    }
};
#endif //FIRSTCPP_ACCOUNTFACTORY_H
