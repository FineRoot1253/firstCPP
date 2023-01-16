//
// Created by 홍준근 on 2023/01/11.
//
#include "AccountRepository.h"
#include "enthusiasm/common/Error.h"
#include <cstring>
#include <iostream>

//AccountRepository::AccountRepository(const Account *accArr, const int &accNum) {
//    this->accArr = accArr;
//}

AccountRepository::AccountRepository(const Account *accArr, const int &accNum) {
    std::copy(accArr, accArr + accNum, this->accArr);
    this->accNum = accNum;
}

BaseDto<Account> AccountRepository::findById(long accId) {
    int i = 0;
    while (i < 100) {
        if (accArr[i].accId == accId) {
            return BaseDto<Account>{accArr[i], Error{false, ""}};
        }
        i++;
    }
    return BaseDto<Account>{Account{}, Error{true, "No Items"}};
}

Account *AccountRepository::findAll() {
    return accArr;
}

BaseDto<int> AccountRepository::getTotalCounts() {
    return BaseDto<int>{accNum,Error{false,""}};
}

Error AccountRepository::saveAccount(Account account) {
    for (int i = 0; i < accNum; ++i) {
        if (accArr[i].accId == account.accId) {
            return Error{true, "중복 계정 id"};
        }
    }
    accArr[accNum].accId = account.accId;
    strcpy(accArr[accNum].cusName, account.cusName);
    accArr[accNum].balance = account.balance;
    accNum ++;
    return Error{false, ""};
}

Error AccountRepository::saveBalance(Account account) {
    for (int i = 0; i < accNum; ++i) {
        if (accArr[i].accId == account.accId) {
            if (account.balance < 0 && (-1 * account.balance) > accArr[i].balance) {
                return Error{true, "잔액부족"};
            }
            accArr[i].balance += account.balance;
            return Error{false, ""};
        }
    }
}


