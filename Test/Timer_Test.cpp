#include <limits.h>
#include <string>
#include "gtest/gtest.h"


#define protected public
#define private public
#include "Timer.h"
#undef protected
#undef private

#include <sstream>

class TimerTest : public ::testing::Test{
protected:
    Timer * t;

    virtual void SetUp()
    {
        t = new Timer;
    }

    virtual void TearDown() {
        // Code here will be called immediately after each test
        // (right before the destructor).
        delete t;
    }
};

TEST_F(TimerTest, set_turbo)
{
    EXPECT_NO_THROW(t->set_Turbo(15));
}

TEST_F(TimerTest, getInstance)
{
    EXPECT_NO_THROW(t->getInstance());
}

TEST_F(TimerTest, sleepANDsleep_in_one_second)
{
    EXPECT_NO_THROW(t->sleep(5));
    EXPECT_NO_THROW(t->sleep_in_one_second_intervals(5));
}