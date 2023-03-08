#include <gtest/gtest.h>
#include "enthusiasm/banking/command/domain/entity/Account.h"
#include "enthusiasm/banking/command/domain/entity/NormalAccount.h"
#include "enthusiasm/banking/command/domain/entity/HighCreditAccount.h"

class AccountFixture : public ::testing::Test {
protected:
    void SetUp() override{
        dummyNormalAccount= new NormalAccount{1l,100000, "Hong",0.01};
        dummyHighCreditAccount=  new HighCreditAccount{1l,100000, "Hong",0.01,CreditGrade::C};
    }
public:
    AccountFixture() : Test() {
    }

    const Account* dummyNormalAccount;
    const Account* dummyHighCreditAccount;
};

TEST_F(AccountFixture, setRepository) {

}