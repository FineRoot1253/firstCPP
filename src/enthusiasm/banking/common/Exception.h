//
// Created by 홍준근 on 2023/01/25.
//

#ifndef FIRSTCPP_EXCEPTION_H
#define FIRSTCPP_EXCEPTION_H

#include <ios>
#include "enthusiasm/banking/common/constants.h"
#include "enthusiasm/banking/common/utils.h"

class IException {
public:
    virtual const char *getReason() const{
        return constants::ex_kr::EX_MSG_COMMON;
    };
};

class IAccountException : public IException {
public:
    const char *getReason() const override {
        return constants::ex_kr::EX_MSG_ACCOUNT;
    };
};

class SystemCallException : public IException{
private:
    char* reason;
public:
    SystemCallException(const char* reason):reason(nullptr){
        this->reason = new char[std::strlen(reason)+1];
        std::strcpy(this->reason, reason);
    }
    ~SystemCallException(){
        delete[] reason;
    }
    const char *getReason() const override{
        return reason;
    };
};

class ViewEntityException : public IException{
private:
    char* reason;
public:
    ViewEntityException(const char* reason):reason(nullptr){
        this->reason = new char[std::strlen(reason)+1];
        std::strcpy(this->reason, reason);
    }
    virtual ~ViewEntityException(){
        delete[] reason;
    }
    const char * getReason() const override {
        return reason;
    };
};

class DuplicatedViewEntityException : public ViewEntityException{
public:
    DuplicatedViewEntityException(const char* reason):ViewEntityException(reason){
    }

    ~DuplicatedViewEntityException(){}

    const char *getReason() const override {
        return ViewEntityException::getReason();
    };
};

class AccountSystemException : public IAccountException {
private:
    char* reason;

public:
    explicit AccountSystemException(const char* reason):reason(nullptr) {
        this->reason = new char[std::strlen(reason)+1];
        std::strcpy(this->reason, reason);
    }

    ~AccountSystemException(){
        if(reason != nullptr){
            delete[] reason;
        }
    }

    const char *getReason() const override {
        return reason;
    };
};

class DepositException : public IAccountException {
private:
    int requireDepositAmount;
public:
    DepositException(int requireDepositAmount)
            : requireDepositAmount(requireDepositAmount) {
    }

     const char *getReason() const override {
        // requireDepositAmount convert to char array
        int amountLen = utils::getIntDigitCounts(requireDepositAmount);
        char *amountStr = new char[amountLen];
        std::snprintf(amountStr, amountLen, "%d", requireDepositAmount);
        // get Memory Space as total result char array & allocating
        int resultLen =
                amountLen + strlen(constants::ex_kr::EX_MSG_DEPOSIT) + 1 + strlen(constants::ex_kr::EX_MSG_DEPOSIT_AMOUNT) + 1;
        char *result = new char[resultLen];
        std::strcpy(result, constants::ex_kr::EX_MSG_DEPOSIT);
        std::strcat(result, constants::ex_kr::EX_MSG_DEPOSIT_AMOUNT);
        std::strcat(result, amountStr);
        return result;
    };
};


class WithdrawException : public IAccountException {
private:
    int balance;
    int requireWithdrawAmount;
public:
    WithdrawException(int balance, int requireWithdrawAmount)
            : balance(balance), requireWithdrawAmount(requireWithdrawAmount) {};

    const char *getReason() const override {
        int amountLen = utils::getIntDigitCounts(requireWithdrawAmount);
        char *amountStr = new char[amountLen];
        char *result;
        if (requireWithdrawAmount <= 0) {
            int resultLen =
                    amountLen + strlen(constants::ex_kr::EX_MSG_WITHDRAW) + 1 + strlen(constants::ex_kr::EX_MSG_WITHDRAW_AMOUNT) + 1;
            result = new char[resultLen];
            std::strcpy(result, constants::ex_kr::EX_MSG_WITHDRAW);
            std::strcat(result, constants::ex_kr::EX_MSG_WITHDRAW_AMOUNT);
            std::strcat(result, amountStr);
            return result;
        }
        int balanceLen = utils::getIntDigitCounts(balance);
        char *balanceStr = new char[balanceLen];
        std::snprintf(balanceStr, balanceLen, "%d", balance);
        int resultLen = amountLen + balanceLen + strlen(constants::ex_kr::EX_MSG_WITHDRAW) + 1 +
                        strlen(constants::ex_kr::EX_MSG_WITHDRAW_AMOUNT) + 1;
        result = new char[resultLen];
        std::strcpy(result, constants::ex_kr::EX_MSG_WITHDRAW_NOT_ENOUGH);
        std::strcat(result, constants::ex_kr::EX_MSG_WITHDRAW_BALANCE);
        std::strcat(result, balanceStr);
        std::strcat(result, constants::ex_kr::EX_MSG_WITHDRAW_AMOUNT);
        std::strcat(result, amountStr);
        return result;

    };
};


#endif //FIRSTCPP_EXCEPTION_H
