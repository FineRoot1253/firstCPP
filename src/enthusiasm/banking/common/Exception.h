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
    virtual const std::string getReason() const{
        return constants::ex_kr::EX_MSG_COMMON;
    };
};

class IAccountException : public IException {
public:
    const std::string getReason() const override {
        return constants::ex_kr::EX_MSG_ACCOUNT;
    };
};

class SystemCallException : public IException{
private:
    std::string reason;
public:
    SystemCallException(std::string reason):reason(std::string()){
    }

    const std::string getReason() const override{
        return reason;
    };
};

class ViewEntityException : public IException{
private:
    std::string reason;
public:
    ViewEntityException(std::string reason):reason(std::string()){
    }

    const std::string getReason() const override {
        return reason;
    };
};

class DuplicatedViewEntityException : public ViewEntityException{
public:
    DuplicatedViewEntityException(std::string reason):ViewEntityException(reason){
    }

    ~DuplicatedViewEntityException(){}

    const std::string getReason() const override {
        return ViewEntityException::getReason();
    };
};

class AccountSystemException : public IAccountException {
private:
    std::string reason;

public:
    explicit AccountSystemException(std::string reason):reason(std::string()) {
    }

    ~AccountSystemException(){
    }

    const std::string getReason() const override {
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

     const std::string getReason() const override {
        std::string result;
        result += constants::ex_kr::EX_MSG_DEPOSIT;
        result += constants::ex_kr::EX_MSG_DEPOSIT_AMOUNT;
        result += std::to_string(requireDepositAmount);
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

    const std::string getReason() const override {
        std::string result;
        if (requireWithdrawAmount <= 0) {
            result += constants::ex_kr::EX_MSG_WITHDRAW;
            result += constants::ex_kr::EX_MSG_WITHDRAW_AMOUNT;
            result += std::to_string(requireWithdrawAmount);
            return result;
        }
        result += constants::ex_kr::EX_MSG_WITHDRAW_NOT_ENOUGH;
        result += constants::ex_kr::EX_MSG_WITHDRAW_BALANCE;
        result += std::to_string(balance);
        result += constants::ex_kr::EX_MSG_WITHDRAW_AMOUNT;
        result += std::to_string(requireWithdrawAmount);
        return result;
    };
};


#endif //FIRSTCPP_EXCEPTION_H
