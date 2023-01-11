#include <gtest/gtest.h>

#include "ch2/date.cpp"

class DateFixture :public::testing::Test{
protected:
    virtual void TearDown(){

    }
    virtual void SetUp(){

    }
public:
    DateFixture(): Test(){
        date = new Date(2012,1,31);
        //date->setDate(2012,1,31);
    }
    virtual  ~DateFixture(){
        delete date;
    }
    Date * date;
};

TEST_F(DateFixture, setDate){
    Date dummy = *date;
    Date * compareTarget = new Date(2012,1,31);
    //compareTarget->setDate(2012,1,31);
    EXPECT_EQ(dummy.getDay(), compareTarget->getDay());
    EXPECT_EQ(dummy.getMonth(), compareTarget->getMonth());
    EXPECT_EQ(dummy.getYear(), compareTarget->getYear());
}

TEST_F(DateFixture, roundUpCheck){
    Date dummy = *date;
    dummy.addMonth(1);
    EXPECT_EQ(dummy.getDay(), 2);
}

TEST_F(DateFixture, addDayCheck){
    Date dummy = *date;
    dummy.addDay(1);
    EXPECT_EQ(dummy.getDay(), 1);
    EXPECT_EQ(dummy.getMonth(), 2);
}

TEST_F(DateFixture, addMonthCheck){
    Date dummy = *date;
    dummy.addMonth(3);
    EXPECT_EQ(dummy.getDay(), 1);
    EXPECT_EQ(dummy.getMonth(), 5);
}

TEST_F(DateFixture, addYearCheck){
    Date dummy = *date;
    dummy.addYear(1);
    EXPECT_EQ(dummy.getYear(), 2013);
}

TEST_F(DateFixture, implicitInitializeCheck){
    Date dummy = *date;
    Date dummy1 = Date(2012, 1, 31);
    EXPECT_EQ(dummy.getYear(), dummy1.getYear());
    EXPECT_EQ(dummy.getMonth(), dummy1.getMonth());
    EXPECT_EQ(dummy.getDay(), dummy1.getDay());
}

TEST_F(DateFixture, explicitInitializeCheck){
    Date dummy = *date;
    Date dummy1(2012, 1, 31);
    EXPECT_EQ(dummy.getYear(), dummy1.getYear());
    EXPECT_EQ(dummy.getMonth(), dummy1.getMonth());
    EXPECT_EQ(dummy.getDay(), dummy1.getDay());
}

TEST_F(DateFixture, defaultInitializeCheck){
    Date dummy;
    EXPECT_EQ(dummy.getYear(), 1997);
    EXPECT_EQ(dummy.getMonth(), 11);
    EXPECT_EQ(dummy.getDay(), 29);
}