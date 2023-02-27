//
// Created by 홍준근 on 2023/02/24.
//

#ifndef FIRSTCPP_NORMALACCOUNT_H
#define FIRSTCPP_NORMALACCOUNT_H

#include "Account.h"

class NormalAccount : public Account {
private:
    double interestRatio;
protected:
    Error deposit(int money) override;

public:
    NormalAccount()
            : Account()
              , interestRatio() {};

    NormalAccount(long accId, int balance, const char *cusName, double interestRatio)
            : Account(accId, balance, cusName)
              , interestRatio(interestRatio) {};

    NormalAccount(const NormalAccount &normalAccount)
            : Account(normalAccount.getAccId(), normalAccount.getBalance(), normalAccount.getCusName())
              , interestRatio(normalAccount.interestRatio) {};

    NormalAccount(const AccountInputDto &accountInputDto)
            : Account(accountInputDto.getAccountID(), accountInputDto.getMoney(), accountInputDto.getCustomerName())
              , interestRatio(accountInputDto.getInterestRatio()) {
    };

    double getInterestRatio() const;

    std::ostream &format(std::ostream &out) const override {
        out << constants::txt_kr::TXT_INPUT_ACCOUNT_ID;
        out << Account::getAccId() << std::endl;
        out << constants::txt_kr::TXT_INPUT_CUSTOMER_NAME;
        out << Account::getCusName() << std::endl;
        out << constants::txt_kr::TXT_INPUT_LEFT;
        out << Account::getBalance() << std::endl;
        out << constants::txt_kr::TXT_OUTPUT_INTEREST;
        out << interestRatio <<"%"<< std::endl;
        return out;
    }
};


#endif //FIRSTCPP_NORMALACCOUNT_H
