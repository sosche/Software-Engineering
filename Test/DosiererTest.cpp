#include <limits.h>
#include <string>
#include "gtest/gtest.h"

#define protected public
#define private public

#include "Dosierer.h"

#undef protected
#undef private

class DosiererTest : public ::testing::Test {
protected:
    Dosierer* dosierer;
    Waage* waage;

    virtual void SetUp() {
        waage= new Waage;
        dosierer= new Dosierer(10, 1000, "zutat", waage, 30);
    }

    virtual void TearDown() {
        delete waage;
        delete dosierer;
    }
};

TEST_F(DosiererTest, refill_Ok){

    dosierer->m_menge=1;
    EXPECT_EQ(dosierer->getMenge(),1);
    dosierer->refill();
    EXPECT_EQ(dosierer->getMenge(), 30);

}

TEST_F(DosiererTest, getter)
{
    int menge=0;
    menge=dosierer->getMenge();
    EXPECT_EQ(menge, 30);
    std::string zutat="";
    zutat=dosierer->getZutat();
    EXPECT_EQ(zutat, "zutat");
}

