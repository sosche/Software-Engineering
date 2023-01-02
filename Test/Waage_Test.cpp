#include <limits.h>
#include <string>
#include "gtest/gtest.h"


#define protected public
#define private public
#include "Waage.h"
#undef protected
#undef private

#include <sstream>

class WaageTest : public ::testing::Test{
protected:
    Waage * m_waage;

    virtual void SetUp()
    {
       m_waage = new Waage;
    }

    virtual void TearDown() {
        // Code here will be called immediately after each test
        // (right before the destructor).
        delete m_waage;
    }
};

TEST_F(WaageTest, changeWeight)
{
    EXPECT_NO_THROW(m_waage->changeWeight(5));
}

TEST_F(WaageTest, tara)
{
    EXPECT_EQ(m_waage->tara(), 0);
}

TEST_F(WaageTest, getWeight)
{
    EXPECT_EQ(m_waage->getWeight(), 0);
}

TEST_F(WaageTest, getDelta)
{
    EXPECT_EQ(m_waage->getDelta(), 0);
}