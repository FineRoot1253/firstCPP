#include <gtest/gtest.h>
#include "enthusiasm/banking/command/domain/entity/Account.h"

class AccountFixture : public ::testing::Test {
public:
    AccountFixture() : Test() {
    }

    const Account dummyAccount= Account{1l,100000, "Hong"};
};

TEST_F(AccountFixture, setRepository) {
    const Account& dummy1 = Account();
    EXPECT_EQ(dummy1.isEmpty(), true);
}