//
// Created by 홍준근 on 2023/01/16.
//
#include "Account.h"
#include "enthusiasm/banking/common/constants.h"

Account::Account():accId(0l), balance(0),cusName(nullptr) {
    cusName = new char[std::strlen(constants::utils::TXT_DEFAULT)+1];
    std::strcpy(this->cusName, constants::utils::TXT_DEFAULT);
}

Account::Account(const Account &account):accId(account.accId), balance(account.balance) , cusName(nullptr){
    if(account.cusName != nullptr){
        cusName = new char[strlen(account.cusName)+1];
        strcpy(this->cusName, account.cusName);
    }
}

Account::Account(long accId, int balance, const char *cusName)
: accId(accId)
, balance(balance){
    this->cusName = new char[strlen(cusName)+1];
    strcpy(this->cusName, cusName);
}

Account::~Account() {
    delete[] cusName;
}

long Account::getAccId() const {
    return accId;
}

int Account::getBalance() const {
    return balance;
}

char *Account::getCusName() const {
    return cusName;
}

void Account::showAccInfo() const {
    std::cout<<"계좌ID: "<<accId<<std::endl;
    std::cout<<"이 름: "<<cusName<<std::endl;
    std::cout<<"잔 액: "<<balance<<std::endl;
}

Error Account::deposit(int money) {
    if (money <= 0){
        return Error{true, constants::err_kr::ERR_MSG_SAVE_INPUT_ERROR_LE};
    }
    balance+=money;
    return Error{};
}

BaseReturnDto<int> Account::withdraw(int money) {
    if (money > balance){
        return BaseReturnDto<int>{0, Error{true, constants::err_kr::EX_MSG_WITHDRAW_OVER}};
    }
    balance-=money;
    return BaseReturnDto<int>{balance, Error{}};
}

Error Account::save(const BalanceDto& balanceDto) {
    switch (balanceDto.getCurrentMode()) {
        case eBankingMode::Deposit:
            return deposit(balanceDto.getBalance());
        case eBankingMode::WithDraw:
            return withdraw(balanceDto.getBalance()).error;
        default:
            break;
    }
    return Error{true,constants::err_kr::ERR_MSG_SAVE_FAILURE};
}

bool Account::isEqual(const Account &other) const{
    return other.getAccId() == accId;
}

bool Account::isNotEqual(const Account &other) const{
    return other.getAccId() != accId;
}

bool Account::isEmpty() const {
    return accId == 0L && balance == 0 && (!std::strcmp(cusName, constants::utils::TXT_DEFAULT));
}

bool Account::isNotEmpty() const {
    return accId != 0L;
}
