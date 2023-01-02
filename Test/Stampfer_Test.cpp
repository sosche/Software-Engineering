#include <limits.h>
#include <string>
#include "gtest/gtest.h"


#define protected public
#define private public
#include "Stampfer.h"
#undef protected
#undef private

class StampferTest: public ::testing::Test
{
protected:
    Stampfer * stampfer;

    virtual void SetUp()
    {
        stampfer = new Stampfer();
    }

    virtual void TearDown()
    {
        // Code here will be called immediately after each test
        // (right before the destructor).
        delete stampfer;
    }
};

TEST_F(StampferTest, sameInstanceOfTimer)
{
    Stampfer * stampfer2= new Stampfer();
    EXPECT_EQ(stampfer2->myTimer, stampfer->myTimer);
    delete stampfer2;
}

TEST_F(StampferTest, defaultValues) {
    EXPECT_EQ(stampfer->doinIt, false);
    EXPECT_EQ(stampfer->zeiteinheit, 0);
    stampfer->setTimer();
    stampfer->putzen();
    EXPECT_EQ(stampfer->doinIt,false);
    EXPECT_EQ(stampfer->zeiteinheit,0);
}

TEST_F(StampferTest,doinIt){
    int testTime=1;

    int time_start, time_end, x;
    time_start = time(NULL);
    stampfer->doIt(testTime);
    time_end = time(NULL);
    x =time_end-time_start;
    EXPECT_EQ(1,testTime);
    EXPECT_LE(x,testTime+1);
}

