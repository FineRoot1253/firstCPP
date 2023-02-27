//
// Created by 홍준근 on 2023/01/11.
//

#ifndef FIRSTCPP_BANKSERVICE_H
#define FIRSTCPP_BANKSERVICE_H

#include "enthusiasm/banking/command/domain/repository/AccountRepository.h"
#include "enthusiasm/banking/command/domain/dto/MoneyInputDto.h"
#include "enthusiasm/banking/common/service.h"

class BankService : public Service{
private:
    AccountRepository* accountRepository;
    BankService();
public:
    explicit BankService(const AccountRepository& accountRepository);
    BankService(const BankService& bankService);
    ~BankService();

    Error makeAccount(const AccountInputDto& accountInputDto);
    Error depositMoney(const MoneyInputDto& moneyInputDto);
    Error withdrawMoney(const MoneyInputDto& moneyInputDto);
    const HGrowableList<Account*>& findAll() const;
    BaseReturnDto<Account*> findById(const long& accountID) const;
};


#endif //FIRSTCPP_BANKSERVICE_H
