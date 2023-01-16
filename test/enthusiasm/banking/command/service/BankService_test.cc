#include <gtest/gtest.h>
#include "enthusiasm/banking/command/service/BankService.h"

class BankServiceFixture : public ::testing::Test {
private:
    AccountRepository *accountRepository;
protected:
    virtual void TearDown() {
    }

    virtual void SetUp() {
        accountRepository->saveAccount(Account{1l,100000, "Hong"});
        accountRepository->saveAccount(Account{2l,200000, "Lee"});
        accountRepository->saveAccount(Account{3l,300000, "Kim"});
        accountRepository->saveAccount(Account{4l,400000, "Choi"});
        bankService = new BankService(*accountRepository);
    }

public:
    BankServiceFixture() : Test() {
        accountRepository = new AccountRepository({},0);
//        bankService = new BankService();
    }

    virtual  ~BankServiceFixture() {
        delete bankService;
    }

    BankService *bankService;
    const Account dummyAccounts[4] = {Account{1l,100000, "Hong"},Account{2l,200000, "Lee"},Account{3l,300000, "Kim"},Account{4l,400000, "Choi"}};
    const int DUMMY_ACCOUNT_COUNT = 4;
};

TEST_F(BankServiceFixture, makeAccount) {
    BankService dummy = *bankService;
    Error err = dummy.makeAccount(Account{5l, 500000, "Park"});
    EXPECT_EQ(err.isError, false);
    Account * accounts = dummy.findAll();
    EXPECT_EQ(accounts[4].balance, 200000);
    for (int i = 0; i < 5; ++i) {
        EXPECT_EQ(dummyAccounts->accId, accounts[i].accId);
        EXPECT_STREQ(dummyAccounts->cusName,accounts[i].cusName);
        EXPECT_EQ(dummyAccounts->balance, accounts[i].balance);
    }
}

TEST_F(BankServiceFixture, depositAccount) {
    BankService dummy = *bankService;

    const Error &error1 = dummy.makeAccount(Account{5l, 100000, "Park"});
    const Error &error2 = dummy.depositMoney(5l, 100000);

    EXPECT_EQ(error1.isError,false);
    EXPECT_EQ(error2.isError,false);

    Account * accounts = dummy.findAll();
    EXPECT_EQ(accounts[4].balance, 200000);

    const Error &error3 = dummy.depositMoney(5l, 0);
    EXPECT_EQ(error3.isError, true);
    EXPECT_STREQ(error3.content,"0보다 작거나 같은 수");

    const Error &error4 = dummy.depositMoney(5l, -100000);
    EXPECT_EQ(error4.isError, true);
    EXPECT_STREQ(error4.content,"0보다 작거나 같은 수");
}

TEST_F(BankServiceFixture, withdrawAccount) {
    BankService dummy = *bankService;

    const Error &error1 = dummy.makeAccount(Account{5l, 100000, "Park"});
    const Error &error2 = dummy.withdrawMoney(5l, -100000);

    EXPECT_EQ(error1.isError, false);
    EXPECT_EQ(error2.isError, false);

    Account * accounts = dummy.findAll();
    EXPECT_EQ(accounts[4].balance, 0);

    const Error &error3 = dummy.withdrawMoney(5l, -100000);
    EXPECT_EQ(error3.isError, true);
    EXPECT_STREQ(error3.content,"잔액부족");

    const Error &error4 = dummy.withdrawMoney(5l, 100000);
    EXPECT_EQ(error4.isError, true);
    EXPECT_STREQ(error4.content,"0보다 크거나 같은 수");

    const Error &error5 = dummy.withdrawMoney(5l, 0);
    EXPECT_EQ(error5.isError, true);
    EXPECT_STREQ(error5.content,"0보다 크거나 같은 수");
}

TEST_F(BankServiceFixture, findAll) {
    BankService dummy = *bankService;
    Error err = dummy.makeAccount(Account{5l, 500000, "Park"});
    EXPECT_EQ(err.isError, false);
    Account * accounts = dummy.findAll();
    for (int i = 0; i < 5; ++i) {
        EXPECT_EQ(dummyAccounts->accId, accounts[i].accId);
        EXPECT_STREQ(dummyAccounts->cusName,accounts[i].cusName);
        EXPECT_EQ(dummyAccounts->balance, accounts[i].balance);
    }
}