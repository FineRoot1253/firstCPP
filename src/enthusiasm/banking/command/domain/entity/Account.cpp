//
// Created by 홍준근 on 2023/01/16.
//
#include "Account.h"

#include <utility>
#include "enthusiasm/banking/common/constants.h"

Account::Account()
        : accId(0l)
        , balance(0)
        , cusName(std::string()) {
}

Account::Account(const Account &account)
        : accId(account.accId)
        , balance(account.balance)
        , cusName(std::string()) {
}

Account::Account(long accId, int balance, std::string  cusName)
        : accId(accId)
        , balance(balance)
        , cusName(std::move(cusName)){
}

Account::~Account() {
}

long Account::getAccId() const {
    return accId;
}

int Account::getBalance() const {
    return balance;
}

std::string Account::getCusName() const {
    return cusName;
}



void Account::showAccInfo() const {
    std::cout << "계좌ID: " << accId << std::endl;
    std::cout << "이 름: " << cusName << std::endl;
    std::cout << "잔 액: " << balance << std::endl;
}

Error Account::deposit(int money) {
    if (money <= 0) {
        return Error{true, constants::err_kr::ERR_MSG_SAVE_INPUT_ERROR_LE};
    }
    balance += money;
    return Error{};
}

BaseReturnDto<int> Account::withdraw(int money) {
    if (money > balance) {
        return BaseReturnDto<int>{0, Error{true, constants::err_kr::EX_MSG_WITHDRAW_OVER}};
    }
    balance -= money;
    return BaseReturnDto<int>{balance, Error{}};
}

Error Account::save(const BalanceDto &balanceDto) {
    switch (balanceDto.getCurrentMode()) {
        case eBankingMode::Deposit:
            return deposit(balanceDto.getBalance());
        case eBankingMode::WithDraw:
            return withdraw(balanceDto.getBalance()).error;
        default:
            break;
    }
    return Error{true, constants::err_kr::ERR_MSG_SAVE_FAILURE};
}

bool Account::isEqual(const Account &other) const {
    return other.getAccId() == accId;
}

bool Account::isNotEqual(const Account &other) const {
    return other.getAccId() != accId;
}

bool Account::isEmpty() const {
    return accId == 0L && balance == 0 && cusName.empty();
}

bool Account::isNotEmpty() const {
    return accId != 0L;
}
