//
// Created by 홍준근 on 2023/01/11.
//

#include "BankService.h"

BankService::BankService(AccountRepository accountRepository) {
    const BaseDto<int> &totalCountsDto = accountRepository.getTotalCounts();
    Account *allData = accountRepository.findAll();
    if(totalCountsDto.error.isError) {
        this->accountRepository = new AccountRepository({}, 0);
    }else{
        this->accountRepository = new AccountRepository(allData, totalCountsDto.data);
    }
}

BankService::~BankService() {
    delete accountRepository;
}

Account *BankService::findAll() {
    return accountRepository->findAll();
}

Error BankService::makeAccount(Account account) {
    return accountRepository->saveAccount(account);
}

Error BankService::depositMoney(const long accId, const int money) {
    if (money <= 0){
        return Error{true, "0보다 작거나 같은 수"};
    }
    return accountRepository->saveBalance(Account{accId, money, ""});
}

Error BankService::withdrawMoney(const long accId, const int money) {
    if (money >= 0){
        return Error{true, "0보다 크거나 같은 수"};
    }
    return accountRepository->saveBalance(Account{accId, money, ""});
}


