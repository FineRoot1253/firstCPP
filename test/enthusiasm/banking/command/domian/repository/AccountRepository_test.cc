#include <gtest/gtest.h>
#include "enthusiasm/banking/command/domain/repository/AccountRepository.h"

class AccountRepositoryFixture : public ::testing::Test {
protected:
    virtual void TearDown() {
    }

    virtual void SetUp() {
        Account ** temp = new Account * [4];
        for (int i = 0; i < 4; ++i) {
            temp[i] = new Account(dummyAccounts[i]);
        }
       const Account* tempDto [4]= {temp[0],temp[1],temp[2],temp[3]};
        accountRepository = new AccountRepository(tempDto, 4);
        for (int i = 0; i < 4; ++i) {
            delete temp[i];
        }
        delete []temp;
    }

public:
    AccountRepositoryFixture() : Test() {
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
        const BaseReturnDto<Account> &dto = dummy.findById(dummyAccounts->getAccId());
        EXPECT_EQ(dummyAccounts->getAccId(), dto.data.getAccId());
        EXPECT_STREQ(dummyAccounts->getCusName(),dto.data.getCusName());
        EXPECT_EQ(dummyAccounts->getBalance(), dto.data.getBalance());
    }
}

TEST_F(AccountRepositoryFixture, saveAccount) {
    AccountRepository dummy = *accountRepository;
    const HGrowableList<Account>& accounts = dummy.findAll();
    AccountRepository *compareRepository = new AccountRepository({},0);
    for (int i = 0; i < dummy.getTotalCounts().data; ++i) {
        const Account &account = accounts.get(i);
        compareRepository->saveAccount(AccountInputDto{account.getAccId(),account.getBalance(),account.getCusName()});
    }
    compareRepository->saveAccount(AccountInputDto{5l, 500000, "Park"});
    EXPECT_EQ(compareRepository->getTotalCounts().data, 5);
    if(!compareRepository->findById(5l).error.isError()){
        const Account &account = compareRepository->findById(5l).data;
        EXPECT_STREQ(account.getCusName(), "Park");
        EXPECT_EQ(account.getBalance(), 500000);
    }
    delete compareRepository;
}

TEST_F(AccountRepositoryFixture, depositAccount) {
    AccountRepository dummy = *accountRepository;
    const Error &error1 = dummy.saveAccount(AccountInputDto{5l, 100000, "Park"});
    const Error &error2 = dummy.saveBalance(BalanceDto{5l, 100000, eBankingMode::Deposit});
    const Account &data =dummy.findById(5l).data;
    EXPECT_EQ(data.getBalance(), 200000);
}

TEST_F(AccountRepositoryFixture, withdrawAccount) {
    AccountRepository dummy = *accountRepository;
    const Error &error1 = dummy.saveAccount(AccountInputDto{5l, 100000, "Park"});
    const Error &error2 = dummy.saveBalance(BalanceDto{5l, 100000, eBankingMode::WithDraw});
    const Account &data =dummy.findById(5l).data;
    EXPECT_EQ(data.getBalance(), 0);
    const Error &error3 = dummy.saveBalance(BalanceDto{5l, 100000, eBankingMode::WithDraw});
    EXPECT_EQ(error3.isError(), true);
    EXPECT_STREQ(error3.getReason(),"너무 많은 액수를 출금");
}

TEST_F(AccountRepositoryFixture, getUserCounts) {
    AccountRepository dummy = *accountRepository;
    EXPECT_EQ(dummy.getTotalCounts().data, 4);
}