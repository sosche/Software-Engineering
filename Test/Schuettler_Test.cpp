#include <limits.h>
#include <string>
#include "gtest/gtest.h"


#define protected public
#define private public
#include "Schuettler.h"
#undef protected
#undef private


#include <sstream>

class SchuettlerTest: public ::testing::Test
{
protected:
    Schuettler * schuettler;

    virtual void SetUp()
    {
        schuettler = new Schuettler();
    }

    virtual void TearDown()
    {
        // Code here will be called immediately after each test
        // (right before the destructor).
        delete schuettler;
    }
};

TEST_F(SchuettlerTest, sameInstanceOfTimer)
{
    Schuettler * schuettler2= new Schuettler();
    EXPECT_EQ(schuettler2->myTimer, schuettler->myTimer);
    delete schuettler2;
}

TEST_F(SchuettlerTest, defaultValues) {
    EXPECT_EQ(schuettler->doinIt, false);
    EXPECT_EQ(schuettler->zeiteinheit, 0);
    schuettler->setTimer();
    schuettler->putzen();
    EXPECT_EQ(schuettler->doinIt,false);
    EXPECT_EQ(schuettler->zeiteinheit,0);
}

TEST_F(SchuettlerTest, callOnDoinIt){


    int testTime=1;

    int time_start, time_end, x;
    time_start = time(NULL);
    schuettler->doIt(testTime);
    time_end = time(NULL);
    x =time_end-time_start;
    EXPECT_EQ(1,testTime);
    EXPECT_LE(x,testTime+1);
}

