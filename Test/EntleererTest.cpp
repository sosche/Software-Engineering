#include <limits.h>
#include <string>
#include "gtest/gtest.h"


#define protected public
#define private public
#include "Entleerer.h"
#undef protected
#undef private

class EntleererTest: public ::testing::Test
{
protected:
    Waage* wg;
    Entleerer *en;
    virtual void SetUp()
    {
        wg = new Waage();
        en= new Entleerer(10,1,wg);
    }
    virtual void TearDown()
    {
        delete wg;
        delete en;
    }
};

TEST_F(EntleererTest,EntleererDestructor)
{
    EXPECT_NO_THROW(en->update());
    EXPECT_NO_THROW(en->doIt(1));
}
