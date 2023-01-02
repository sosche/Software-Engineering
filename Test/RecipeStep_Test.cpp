#include <limits.h>
#include <string>
#include "gtest/gtest.h"


#define protected public
#define private public
#include "RecipeStep.h"
#undef protected
#undef private


#include <sstream>

class RecipeStepTest: public ::testing::Test
{
protected:
    RecipeStep * recipeStep;

    virtual void SetUp()
    {
        recipeStep = new RecipeStep();
    }

    virtual void TearDown()
    {
        // Code here will be called immediately after each test
        // (right before the destructor).
        delete recipeStep;
    }
};

TEST_F(RecipeStepTest, getterAndSetter_ok)
{
    float menge=3.1415;
    std::string pi="pi";
    recipeStep->setMenge(menge);
    EXPECT_EQ(recipeStep->getMenge(), menge);
    recipeStep->setZutat(pi);
    EXPECT_EQ(recipeStep->getZutat(),pi);

}

