//
// Created by 홍준근 on 2023/01/30.
//

#ifndef FIRSTCPP_ACCOUNTINPUTDTO_H
#define FIRSTCPP_ACCOUNTINPUTDTO_H

#include <iostream>
#include "enthusiasm/banking/common/BankingMode.h"
#include "enthusiasm/banking/common/constants.h"
#include "AccountTypeInputDto.h"
#include "enthusiasm/banking/common/utils.h"
#include "CreditGradeInputDto.h"

class AccountInputDto {
private:
    long accountID;
    int money;
    char *customerName;
    AccountTypeInputDto accountType;
    CreditGradeInputDto creditGrade;
    double interestRatio;

public:
    //FOR HIGH CREDIT
    explicit AccountInputDto(const long& accountID, const int& money, const char *customerName,
                    const double &interestRatio, const CreditGradeInputDto &creditGrade)
            : accountID(accountID)
              , accountType(AccountTypeInputDto(2))
              , creditGrade(creditGrade)
              , money(money)
              , interestRatio(interestRatio) {
        this->customerName = new char[std::strlen(customerName) + 1];
        std::strcpy(this->customerName, customerName);
    };

    //FOR NORMAL
    explicit AccountInputDto(long accountID = 0L, int money = 0, const char *customerName = "",
                    const double &interestRatio = 0.00)
            : accountID(accountID)
              , accountType(AccountTypeInputDto(1))
              , creditGrade(CreditGradeInputDto(1))
              , money(money)
              , interestRatio(interestRatio) {
        this->customerName = new char[std::strlen(customerName) + 1];
        std::strcpy(this->customerName, customerName);
    };

    ~AccountInputDto() {
        delete customerName;
    }

public:
    long getAccountID() const {
        return accountID;
    };

    int getMoney() const {
        return money;
    }

    const char *getCustomerName() const {
        return customerName;
    }

    AccountType getAccountType() const {
        return accountType.toAccountType();
    }

    CreditGrade getCreditGrade()const{
        return utils::Parser::intToCreditGrade(creditGrade.getValue());
    }

    double getInterestRatio() const {
        return interestRatio;
    }


    friend std::istream &operator>>(std::istream &in, AccountInputDto &accountInputDto) {
        in >> accountInputDto.accountType;
        std::cout << constants::txt_kr::TXT_INPUT_ACCOUNT_ID;
        in >> accountInputDto.accountID;
        std::cout << constants::txt_kr::TXT_INPUT_CUSTOMER_NAME;
        in >> accountInputDto.customerName;
        std::cout << constants::txt_kr::TXT_INPUT_DEPOSIT;
        in >> accountInputDto.money;
        std::cout << constants::txt_kr::TXT_INPUT_INTEREST;
        in >> accountInputDto.interestRatio;
        if(accountInputDto.interestRatio < 0){
            throw AccountSystemException(constants::ex_kr::EX_MSG_SYS_ILLEGAL_INPUT);
        }
        if (accountInputDto.accountType.toAccountType() == AccountType::HIGH_CREDIT) {
            in >> accountInputDto.creditGrade;
        }
        return in;
    };
};

#endif //FIRSTCPP_ACCOUNTINPUTDTO_H
