#include <gtest/gtest.h>
#include "enthusiasm/banking/command/domain/repository/AccountRepository.h"

class AccountRepositoryFixture : public ::testing::Test {
protected:
    virtual void TearDown() {
    }

    virtual void SetUp() {
        accountRepository->saveAccount(Account{1l,100000, "Hong"});
        accountRepository->saveAccount(Account{2l,200000, "Lee"});
        accountRepository->saveAccount(Account{3l,300000, "Kim"});
        accountRepository->saveAccount(Account{4l,400000, "Choi"});
    }

public:
    AccountRepositoryFixture() : Test() {
        accountRepository = new AccountRepository({},0);
    }

    virtual  ~AccountRepositoryFixture() {
        delete accountRepository;
    }

    AccountRepository *accountRepository;
    const Account dummyAccounts[4] = {Account{1l,100000, "Hong"},Account{2l,200000, "Lee"},Account{3l,300000, "Kim"},Account{4l,400000, "Choi"}};
    const int DUMMY_ACCOUNT_COUNT = 4;
};

TEST_F(AccountRepositoryFixture, setRepository) {
    AccountRepository dummy = *accountRepository;
    for (int i = 0; i < DUMMY_ACCOUNT_COUNT; ++i) {
        const BaseDto<Account> &dto = dummy.findById(dummyAccounts->accId);
        EXPECT_EQ(dummyAccounts->accId, dto.data.accId);
        EXPECT_STREQ(dummyAccounts->cusName,dto.data.cusName);
        EXPECT_EQ(dummyAccounts->balance, dto.data.balance);
    }
}

TEST_F(AccountRepositoryFixture, saveAccount) {
    AccountRepository dummy = *accountRepository;
    Account *accounts = dummy.findAll();
    AccountRepository *compareRepository = new AccountRepository({},0);
    for (int i = 0; i < dummy.getTotalCounts().data; ++i) {
        compareRepository->saveAccount(Account{accounts[i].accId,accounts[i].balance, *accounts[i].cusName});
    }
    compareRepository->saveAccount(Account{5l, 500000, "Park"});
    EXPECT_EQ(compareRepository->getTotalCounts().data, 5);
    char *name = compareRepository->findById(5l).data.cusName;
    int balance = compareRepository->findById(5l).data.balance;
    EXPECT_STREQ(name, "Park");
    EXPECT_EQ(balance, 500000);
    delete compareRepository;
}

TEST_F(AccountRepositoryFixture, depositAccount) {
    AccountRepository dummy = *accountRepository;
    const Error &error1 = dummy.saveAccount(Account{5l, 100000, "Park"});
    const Error &error2 = dummy.saveBalance(Account{5l, 100000, "Park"});
    const Account &data =dummy.findById(5l).data;
    EXPECT_EQ(data.balance, 200000);
}

TEST_F(AccountRepositoryFixture, withdrawAccount) {
    AccountRepository dummy = *accountRepository;
    const Error &error1 = dummy.saveAccount(Account{5l, 100000, "Park"});
    const Error &error2 = dummy.saveBalance(Account{5l, -100000, "Park"});
    const Account &data =dummy.findById(5l).data;
    EXPECT_EQ(data.balance, 0);
    const Error &error3 = dummy.saveBalance(Account{5l, -100000, "Park"});
    EXPECT_EQ(error3.isError, true);
    EXPECT_STREQ(error3.content,"잔액부족");
}

TEST_F(AccountRepositoryFixture, getUserCounts) {
    AccountRepository dummy = *accountRepository;
    EXPECT_EQ(dummy.getTotalCounts().data, 4);
}