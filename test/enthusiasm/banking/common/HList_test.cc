//
// Created by 홍준근 on 2023/01/22.
//
#include "enthusiasm/banking/common/HGrowableList.h"
#include "enthusiasm/banking/common/Exception.h"
#include "enthusiasm/banking/common/Long.h"
#include "enthusiasm/banking/command/domain/entity/Account.h"
#include <gtest/gtest.h>

class HListFixture : public ::testing::Test {
protected:
    virtual void TearDown() {
    }

    virtual void SetUp() {
        Long **temp = new Long *[4];
        for (int i = 0; i < 4; ++i) {
            temp[i] = new Long(dummyArray[i]);
        }
        const Long * tempDto [4]= {temp[0],temp[1],temp[2],temp[3] };
        hList->addArray(tempDto, 4);
        for (int i = 0; i < 4; ++i) {
            delete temp[i];
        }
        delete[]temp;
        hListForAccount->add(Account(1L, 10000, "Hong"));
    }

    HGrowableList<Long> *hList;
    HGrowableList<Account> *hListForAccount;

public:
    HListFixture() : Test() {
        hList = new HGrowableList<Long>();
        hListForAccount = new HGrowableList<Account>();
    }
    ~HListFixture() {
        delete hList;
    }

    const Long dummyArray[4] = {Long(1L), Long(2L), Long(3L), Long(4L)};
};

TEST_F(HListFixture, setElements) {
    for (int i = 0; i < 4; ++i) {
        EXPECT_EQ(true, dummyArray[i].isEqual(hList->get(i)));
    }
}

TEST_F(HListFixture, addElement) {
    for (int i = 0; i < 4; ++i) {
        EXPECT_EQ(true, dummyArray[i].isEqual(hList->get(i)));
    }
    hList->add(5L);
    EXPECT_EQ(true, Long(5L).isEqual(hList->get(4)));
}

TEST_F(HListFixture, clear) {
    hList->clear();
    EXPECT_THROW(hList->get(1), SystemCallException);
}

TEST_F(HListFixture, replace) {
    hList->replace(3,100L);
    EXPECT_EQ(true, Long(100L).isEqual(hList->get(3)));
}

TEST_F(HListFixture, replace_failure) {
    EXPECT_THROW(hList->replace(5,100L), SystemCallException);
}

TEST_F(HListFixture, getForSave) {
    Account &data = hListForAccount->getForSave(0);
    data.save(BalanceDto(1L,20000, eBankingMode::Deposit));
    const Account &result =hListForAccount->get(0);
    EXPECT_EQ(30000, result.getBalance());
}

TEST_F(HListFixture, isExist) {
    EXPECT_EQ(true, hListForAccount->isExist(Account(1L,0,"?")));
}