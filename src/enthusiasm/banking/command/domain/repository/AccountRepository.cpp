//
// Created by 홍준근 on 2023/01/11.
//
#include "AccountRepository.h"
#include "enthusiasm/common/Error.h"
#include "enthusiasm/banking/common/constants.h"
#include "enthusiasm/banking/command/domain/dto/AccountInputDto.h"
#include <iostream>

AccountRepository::AccountRepository()
: accNum(0)
, accList(new HGrowableList<Account>()) {
    accNum = 0;
}

AccountRepository::AccountRepository(const AccountRepository &accountRepository):accNum(accountRepository.accNum), accList(accountRepository.accList){
    accList = new HGrowableList<Account>();
    accList->addArray(accountRepository.accList->getAll(),accNum);
}

AccountRepository::AccountRepository(const Account **accArr, const int &accNum)
        : accNum(accNum), accList(new HGrowableList<Account>()){
    accList->addArray(accArr,accNum);
}

AccountRepository::~AccountRepository() {
    delete accList;
}

BaseReturnDto<Account> AccountRepository::findById(const long& accId) const {
    int i = 0;
    while (i < accNum) {
        if (accList->get(i).getAccId() == accId) {
            return BaseReturnDto<Account>{accList->get(i), Error{}};
        }
        i++;
    }
    return BaseReturnDto<Account>{Account{}, Error{true, constants::err_kr::ERR_MSG_ACCOUNT_ID_NOT_FOUND}};
}

const HGrowableList<Account>& AccountRepository::findAll() const {
    return *accList;
}

BaseReturnDto<int> AccountRepository::getTotalCounts() const {
    return BaseReturnDto<int>{accNum, Error{false, constants::err_kr::ERR_MSG_NO_ERROR}};
}

Error AccountRepository::saveAccount(const AccountInputDto& accountInputDto) {
    for (int i = 0; i < accNum; ++i) {
        if (accList->get(i).getAccId() == accountInputDto.getAccountID()) {
            return Error{true, constants::err_kr::ERR_MSG_ACCOUNT_ID_DUPLICATED};
        }
    }
    accList->add(Account(accountInputDto.getAccountID(), accountInputDto.getMoney(), accountInputDto.getCustomerName()));
    accNum++;
    return Error{};
}

Error AccountRepository::saveBalance(const BalanceDto& balanceDto) {
    for (int i = 0; i < accNum; ++i) {
        if (accList->get(i).getAccId() == balanceDto.getAccId()) {
            return accList->getForSave(i).save(balanceDto);
        }
    }
    return Error{true, constants::err_kr::ERR_MSG_ACCOUNT_ID_NOT_FOUND};
}


