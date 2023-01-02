#include <limits.h>
#include "gtest/gtest.h"

#include "Recipe.h"
#include "RecipeStep.h"

class RecipeTest :public ::testing::Test {
protected:
    Recipe *r;

    virtual void SetUp() {
        r = new Recipe;
    }

    virtual void TearDown() {
        delete r;
    }
};

TEST_F(RecipeTest, checkRecipe) {
    r->setName("Test-Cocktail");
    r->appendStep("Test-Zutat-1", 8);
    r->appendStep("Test-Zutat-2", 15);
    r->appendStep("Stampfen", 20);
    r->appendStep("Test-Zutat-3", 90);
    r->appendStep("Test-Zutat-4", 5);
    r->appendStep("Mischen", 10);

    EXPECT_EQ(r->getName(), "Test-Cocktail");
    EXPECT_EQ(r->getNoOfRecipeSteps(), 6);
    EXPECT_EQ(r->getRecipeStep(0)->getZutat(), "Test-Zutat-1");
    EXPECT_EQ(r->getRecipeStep(0)->getMenge(), 8);
}