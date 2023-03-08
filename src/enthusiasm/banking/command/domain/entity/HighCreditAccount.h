//
// Created by 홍준근 on 2023/02/24.
//

#ifndef FIRSTCPP_HIGHCREDITACCOUNT_H
#define FIRSTCPP_HIGHCREDITACCOUNT_H

#include "NormalAccount.h"
#include "enthusiasm/banking/common/CreditGrade.h"

class HighCreditAccount : public NormalAccount {
private:
    CreditGrade creditGrade;

private:
    Error deposit(int money) override;

public:
    HighCreditAccount():NormalAccount(),creditGrade(CreditGrade::C){};

    HighCreditAccount(const long &accId, const int &balance, const std::string cusName, const double &interestRatio,
                      const CreditGrade &creditGrade)
            : NormalAccount(accId, balance, cusName, interestRatio)
              , creditGrade(creditGrade) {};

    HighCreditAccount(const HighCreditAccount &highCreditAccount)
            : NormalAccount(highCreditAccount.getAccId(), highCreditAccount.getBalance(),
                            highCreditAccount.getCusName(), highCreditAccount.getInterestRatio())
              , creditGrade(highCreditAccount.creditGrade) {};

    HighCreditAccount(const AccountInputDto &accountInputDto)
            : NormalAccount(accountInputDto.getAccountID(), accountInputDto.getMoney(),
                            accountInputDto.getCustomerName(), accountInputDto.getInterestRatio())
              , creditGrade(accountInputDto.getCreditGrade()) {};

    std::ostream &format(std::ostream &out) const override {
        out << constants::txt_kr::TXT_INPUT_ACCOUNT_ID;
        out << Account::getAccId() << std::endl;
        out << constants::txt_kr::TXT_INPUT_CUSTOMER_NAME;
        out << Account::getCusName() << std::endl;
        out << constants::txt_kr::TXT_INPUT_LEFT;
        out << Account::getBalance() << std::endl;
        out << constants::txt_kr::TXT_OUTPUT_INTEREST;
        out << NormalAccount::getInterestRatio() << std::endl;
        out << constants::txt_kr::TXT_INPUT_CREDIT_GRADE;
        out << utils::Parser::creditGradeToChar(creditGrade) << std::endl;
        return out;
    }
};


#endif //FIRSTCPP_HIGHCREDITACCOUNT_H
