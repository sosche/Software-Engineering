#include "limits.h"
#include "gtest/gtest.h"
#include "time.h"


#define private public
#define protected public
#include "Mixer.h"
#include "Timer.h"

#undef private
#undef protected

class MixerTest : public ::testing::Test {
protected:
    Mixer *m;
    int boost;

    virtual void SetUp() {
        m = new Mixer();
        boost=Timer::getInstance()->booster;
    }

    virtual void TearDown() {
        delete m;
        Timer::getInstance()->set_Turbo(boost);
    }
};

TEST_F(MixerTest, checkTime) {

    Timer::getInstance()->set_Turbo(1000);

    int time_start, time_end, x, y;
    time_start = time(NULL);
    m->doIt(5);
    time_end = time(NULL);
    x = time_start - time_end;
    time_start = time(NULL);
    m->myTimer->sleep_in_one_second_intervals(5*1000);
    time_end = time(NULL);
    y = time_start - time_end;

    EXPECT_EQ(x, y);

}