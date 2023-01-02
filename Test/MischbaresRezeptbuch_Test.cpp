#include <limits.h>
#include "gtest/gtest.h"

#define private public
#define protected public
#include "MischbaresRezeptbuch.h"
#include "Recipe.h"
#include "RecipeBook.h"
#undef private
#undef protected

class MischbaresRezeptbuchTest : public ::testing::Test {
protected:
    MischbaresRezeptbuch *m1, *m2;
    Recipe *r0, *r1, *r2;
    VorhandeneZutaten* v;

    virtual void SetUp() {

        v = new VorhandeneZutaten();
        m1 = new MischbaresRezeptbuch(v);


        m2 = new MischbaresRezeptbuch();
        m2->setZutatenVerwalter(v);
        r0 = m2->getRecipe(0);
        r1 = m2->getRecipe(1);
        r2 = m2->getRecipe(2);
    }

    virtual void TearDown() {
        delete m1;
        delete m2;
        delete r0;
        delete r1;
        delete r2;
        delete v;
    }
};

TEST_F(MischbaresRezeptbuchTest, getZutatReturnsCorrectZutat) {
    EXPECT_TRUE(m1->zutatExists("Limettenstuecke"));
    EXPECT_TRUE(m1->zutatExists("Zucker"));
    EXPECT_TRUE(m1->zutatExists("Cointreau"));
    EXPECT_TRUE(m1->zutatExists("Cachaca"));
    EXPECT_TRUE(m1->zutatExists("Eis"));
    EXPECT_TRUE(m1->zutatExists("Wodka"));
    EXPECT_TRUE(m1->zutatExists("Rum weiss"));
    EXPECT_TRUE(m1->zutatExists("Zitronensaft"));
    EXPECT_TRUE(m1->zutatExists("Grenadine"));
    EXPECT_TRUE(m1->zutatExists("Limettensaft"));
    EXPECT_TRUE(m1->zutatExists("Tequilla"));
    EXPECT_TRUE(m1->zutatExists("Gin"));
    EXPECT_TRUE(m1->zutatExists("Noilly Prat"));

    EXPECT_FALSE(m1->zutatExists("Wasser"));
    EXPECT_FALSE(m1->zutatExists("Cola"));
}

TEST_F(MischbaresRezeptbuchTest, correctSeiteRausreissen) {
    EXPECT_EQ(r0->getName(), "Caipirinha");
    EXPECT_EQ(r1->getName(), "Margarita");
    EXPECT_EQ(r2->getName(), "Daiquiri");

    int before = m2->getNumberOfRecipes();
    m2->seitenRausreissen();
    int after = m2->getNumberOfRecipes();
    EXPECT_TRUE(before != after);

    r0 = m2->getRecipe(0);
    r1 = m2->getRecipe(1);
    r2 = m2->getRecipe(2);

    EXPECT_EQ(r0->getName(), "Caipirinha");
    EXPECT_EQ(r1->getName(), "Margarita");
    EXPECT_EQ(r2->getName(), "Caipiroska");


}