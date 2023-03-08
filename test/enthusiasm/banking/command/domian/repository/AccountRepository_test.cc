#include <gtest/gtest.h>
#include "enthusiasm/banking/command/domain/repository/AccountRepository.h"
#include "enthusiasm/banking/command/domain/entity/HighCreditAccount.h"

class AccountRepositoryFixture : public ::testing::Test {
protected:
    virtual void SetUp() {
        accountRepository = new AccountRepository();
        for (int i = 0; i < DUMMY_ACCOUNT_COUNT; ++i) {
            accountRepository->saveAccount(dummyInputDtos[i]);
        }
    }

public:
    AccountRepositoryFixture()
            : Test() {
    }

    virtual  ~AccountRepositoryFixture() {
        delete accountRepository;
        for (int i = 0; i < DUMMY_ACCOUNT_COUNT; ++i) {
            delete dummyAccounts[i];
        }
    }

    AccountRepository *accountRepository;
    const int DUMMY_ACCOUNT_COUNT = 8;
    const AccountInputDto dummyInputDtos[8] = {
            AccountInputDto(1L, 10000, "Hong", 0.01),
            AccountInputDto(2L, 20000, "Kim", 0.02),
            AccountInputDto(3L, 30000, "Lee", 0.03),
            AccountInputDto(4L, 40000, "Park", 0.04),
            AccountInputDto(5L, 50000, "Hong", 0.05,
                            CreditGradeInputDto(utils::Parser::creditGradeToInt(CreditGrade::A))),
            AccountInputDto(6L, 50000, "Gong", 0.05,
                            CreditGradeInputDto(utils::Parser::creditGradeToInt(CreditGrade::B))),
            AccountInputDto(7L, 50000, "Kim", 0.05,
                            CreditGradeInputDto(utils::Parser::creditGradeToInt(CreditGrade::C))),
            AccountInputDto()
    };
    const Account *dummyAccounts[8] = {
            new NormalAccount(1L, 10000, "Hong", 0.01),
            new NormalAccount(2L, 20000, "Kim", 0.02),
            new NormalAccount(3L, 30000, "Lee", 0.03),
            new NormalAccount(4L, 40000, "Park", 0.04),
            new HighCreditAccount(5L, 50000, "Hong", 0.05, CreditGrade::A),
            new HighCreditAccount(6L, 50000, "Gong", 0.05, CreditGrade::B),
            new HighCreditAccount(7L, 50000, "Kim", 0.05, CreditGrade::C),
            new NormalAccount()
    };
};

TEST_F(AccountRepositoryFixture, setRepository) {
    try {
        AccountRepository dummy = *accountRepository;
        for (int i = 0; i < DUMMY_ACCOUNT_COUNT; ++i) {
            const BaseReturnDto<Account*> &dto = dummy.findById(dummyAccounts[i]->getAccId());
            EXPECT_EQ(dummyAccounts[i]->getAccId(), dto.data->getAccId());
            EXPECT_STREQ(dummyAccounts[i]->getCusName(), dto.data->getCusName());
            EXPECT_EQ(dummyAccounts[i]->getBalance(), dto.data->getBalance());
        }
    } catch (IException &exception) {
        std::cout << "exception: " << exception.getReason() << std::endl;
    }

}

TEST_F(AccountRepositoryFixture, saveAccount) {
    AccountRepository dummy = *accountRepository;
    const HGrowableList<Account *> &accounts = dummy.findAll();
    AccountRepository *compareRepository = new AccountRepository();
    for (int i = 0; i < dummy.getTotalCounts().data; ++i) {
        const Account *account = accounts.get(i);
        compareRepository->saveAccount(
                AccountInputDto{account->getAccId(), account->getBalance(), account->getCusName()});
    }
    const Error &result = compareRepository->saveAccount(AccountInputDto{5l, 500000, "Park"});
    EXPECT_EQ(result.isError(), true);
    EXPECT_STREQ(result.getReason(), constants::err_kr::ERR_MSG_ACCOUNT_ID_DUPLICATED);
    delete compareRepository;
}

TEST_F(AccountRepositoryFixture, depositAccount) {
    AccountRepository dummy = *accountRepository;
    const Error &error1 = dummy.saveAccount(AccountInputDto{9L, 100000, "Park"});
    const Error &error2 = dummy.saveBalance(BalanceDto{9L, 100000, eBankingMode::Deposit});
    const Account *data = dummy.findById(9L).data;
    EXPECT_EQ(data->getBalance(), 200000);
}

TEST_F(AccountRepositoryFixture, withdrawAccount) {
    AccountRepository dummy = *accountRepository;
    const Error &error1 = dummy.saveAccount(AccountInputDto{9L, 100000, "Park"});
    const Error &error2 = dummy.saveBalance(BalanceDto{9L, 100000, eBankingMode::WithDraw});
    const Account *data = dummy.findById(9L).data;
    EXPECT_EQ(data->getBalance(), 0);
    const Error &error3 = dummy.saveBalance(BalanceDto{9L, 100000, eBankingMode::WithDraw});
    EXPECT_EQ(error3.isError(), true);
    EXPECT_STREQ(error3.getReason(), "너무 많은 액수를 출금");
}

TEST_F(AccountRepositoryFixture, getUserCounts) {
    AccountRepository dummy = *accountRepository;
    EXPECT_EQ(dummy.getTotalCounts().data, DUMMY_ACCOUNT_COUNT);
}