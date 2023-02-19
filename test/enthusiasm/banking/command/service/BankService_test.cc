#include <gtest/gtest.h>
#include "enthusiasm/banking/command/service/BankService.h"
#include "enthusiasm/banking/command/domain/dto/MoneyInputDto.h"

class BankServiceFixture : public ::testing::Test {
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
        bankService = new BankService(*accountRepository);
    }

    AccountRepository *accountRepository;
    BankService *bankService;

public:
    BankServiceFixture() : Test() {
    }

    ~BankServiceFixture() {
        delete bankService;
    }


    AccountRepository getRepository() const {
        return *accountRepository;
    }

    const Account dummyAccounts[4] = {Account{1l, 100000, "Hong"}, Account{2l, 200000, "Lee"},
                                      Account{3l, 300000, "Kim"}, Account{4l, 400000, "Choi"}};
    const int DUMMY_ACCOUNT_COUNT = 4;
};

TEST_F(BankServiceFixture, makeAccount) {
    Error err = bankService->makeAccount(AccountInputDto{5l, 500000, "Park"});
    EXPECT_EQ(err.isError(), false);
    const HGrowableList<Account> &accounts = bankService->findAll();
    EXPECT_EQ(accounts.get(4).getBalance(), 500000);
}

TEST_F(BankServiceFixture, depositAccount) {
    const Error &error1 = bankService->makeAccount(AccountInputDto{5l, 100000, "Park"});
    const Error &error2 = bankService->depositMoney(MoneyInputDto(5l, 100000, eBankingMode::Deposit));

    EXPECT_EQ(error1.isError(), false);
    EXPECT_EQ(error2.isError(), false);

    const HGrowableList<Account> &accounts = bankService->findAll();
    EXPECT_EQ(accounts.get(4).getBalance(), 200000);

    const Error &error3 = bankService->depositMoney(MoneyInputDto(5l, 0, eBankingMode::Deposit));
    EXPECT_EQ(error3.isError(), true);
    EXPECT_STREQ(error3.getReason(), "0보다 작거나 같은 수");

    const Error &error4 = bankService->depositMoney(MoneyInputDto(5l, -100000, eBankingMode::Deposit));
    EXPECT_EQ(error4.isError(), true);
    EXPECT_STREQ(error4.getReason(), "0보다 작거나 같은 수");
}

TEST_F(BankServiceFixture, withdrawAccount) {
    const Error &error1 = bankService->makeAccount(AccountInputDto{5l, 100000, "Park"});
    const Error &error2 = bankService->withdrawMoney(MoneyInputDto(5l, 100000, eBankingMode::WithDraw));

    EXPECT_EQ(error1.isError(), false);
    EXPECT_EQ(error2.isError(), false);

    const HGrowableList<Account> &accounts = bankService->findAll();
    EXPECT_EQ(accounts.get(4).getBalance(), 0);

    const Error &error3 = bankService->withdrawMoney(MoneyInputDto(5l, 100000, eBankingMode::WithDraw));
    EXPECT_EQ(error3.isError(), true);
    EXPECT_STREQ(error3.getReason(), "너무 많은 액수를 출금");

    const Error &error5 = bankService->withdrawMoney(MoneyInputDto(5l, 0, eBankingMode::WithDraw));
    EXPECT_EQ(error5.isError(), true);
    EXPECT_STREQ(error5.getReason(), "0보다 작거나 같은 수");
}

TEST_F(BankServiceFixture, findAll) {
    Error err = bankService->makeAccount(AccountInputDto{5l, 500000, "Park"});
    EXPECT_EQ(err.isError(), false);
    const HGrowableList<Account> &accounts = bankService->findAll();
    for (int i = 0; i < 4; ++i) {
        EXPECT_EQ(dummyAccounts[i].getAccId(), accounts.get(i).getAccId());
        EXPECT_STREQ(dummyAccounts[i].getCusName(), accounts.get(i).getCusName());
        EXPECT_EQ(dummyAccounts[i].getBalance(), accounts.get(i).getBalance());
    }
    EXPECT_EQ(accounts.get(4).getAccId(), 5l);
    EXPECT_STREQ(accounts.get(4).getCusName(), "Park");
    EXPECT_EQ(accounts.get(4).getBalance(), 500000);
}