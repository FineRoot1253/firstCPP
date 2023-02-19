#include "enthusiasm/banking/common/utils.h"
#include <gtest/gtest.h>

class Utils_TestFixture : public ::testing::Test{
protected:
    virtual void TearDown() {
    }

    virtual void SetUp() {
        data = 3000;
    }
    int data;
public:
    Utils_TestFixture():Test(){

    }

};

TEST_F(Utils_TestFixture, logTest) {
    std::cout<<"result: "<<log2(data)<<std::endl;
}

