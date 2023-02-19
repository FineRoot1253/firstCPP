//
// Created by 홍준근 on 2023/01/11.
//

#include "BankService.h"
#include "enthusiasm/banking/command/domain/dto/MoneyInputDto.h"

BankService::BankService() {

}

BankService::BankService(const AccountRepository& accountRepository)
: accountRepository(new AccountRepository(accountRepository)) {
}

BankService::BankService(const BankService & bankService) :accountRepository(new AccountRepository(*bankService.accountRepository)){
}

BankService::~BankService() {
    if(accountRepository!= nullptr){
        delete accountRepository;
    }
}

const HGrowableList<Account>& BankService::findAll() const {
    return accountRepository->findAll();
}

Error BankService::makeAccount(const AccountInputDto& accountInputDto) {
    return accountRepository->saveAccount(accountInputDto);
}

Error BankService::depositMoney(const MoneyInputDto& moneyInputDto) {
    if (moneyInputDto.getMoney() <= 0){
        return Error{true, constants::err_kr::ERR_MSG_SAVE_INPUT_ERROR_LE};
    }
    return accountRepository->saveBalance(BalanceDto{moneyInputDto.getAccountID(), moneyInputDto.getMoney(), eBankingMode::Deposit});
}

Error BankService::withdrawMoney(const MoneyInputDto& moneyInputDto) {
    if (moneyInputDto.getMoney() <= 0){
        return Error{true, constants::err_kr::ERR_MSG_SAVE_INPUT_ERROR_LE};
    }
    return accountRepository->saveBalance(BalanceDto{moneyInputDto.getAccountID(), moneyInputDto.getMoney(), eBankingMode::WithDraw});
}

BaseReturnDto<Account> BankService::findById(const long& accountID) const {
    return accountRepository->findById(accountID);
}


