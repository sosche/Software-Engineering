#include <limits.h>
#include <string>
#include "gtest/gtest.h"

#define protected public
#define private public

#include "CocktailPro.h"

#undef protected
#undef private

class CocktailProTest : public ::testing::Test {
protected:
    CocktailPro *c;
    int booster;

    virtual void SetUp() {
        char *tmp[] = {};
        c = new CocktailPro(0, tmp);
        c->theMischbaresRezeptbuch->getRecipe(1)->setCounter();
        booster = Timer::getInstance()->booster;
    }

    virtual void TearDown() {
        Timer::getInstance()->booster = booster;
        delete c;
    }
};

TEST_F(CocktailProTest, correctCoyping) {
    CocktailPro *c_copy = new CocktailPro(*c);
    EXPECT_NE(c->theMischbaresRezeptbuch, c_copy->theMischbaresRezeptbuch);
    EXPECT_NE(c->theMischbaresRezeptbuch, nullptr);
    EXPECT_NE(c->theCocktailZubereiter, c_copy->theCocktailZubereiter);
    EXPECT_NE(c->theCocktailZubereiter, nullptr);
    EXPECT_NE(c->theDeviceVerwalter, c_copy->theDeviceVerwalter);
    EXPECT_NE(c->theDeviceVerwalter, nullptr);
    EXPECT_NE(c->theZutatenVerwalter, c_copy->theZutatenVerwalter);
    EXPECT_NE(c->theZutatenVerwalter, nullptr);
    delete c_copy;
}

TEST_F(CocktailProTest, demoTest_DFlagOK) {

    CocktailPro *tmp = c;
    std::string paramString = "-D";
    char param[paramString.size()];

    for (int i = 0; i < paramString.size(); ++i) {
        param[i] = paramString[i];
    }
    char *params[2];
    params[1] = param;

    c = new CocktailPro(2, params);
    c->demo();
    Timer *timer = Timer::getInstance();
    EXPECT_EQ(timer->booster, 1000);
    delete c;
    c = tmp;
}

TEST_F(CocktailProTest, demoTest_NoDFlag) {

    std::string paramString = "-A";
    char param[paramString.size()];

    for (int i = 0; i < paramString.size(); ++i) {
        param[i] = paramString[i];
    }
    char *params[2];
    params[1] = param;

    c = new CocktailPro(2, params);
    c->demo();
    EXPECT_EQ(Timer::getInstance()->booster, 10);

}

TEST_F(CocktailProTest, demoFunction) {
    Timer::getInstance()->booster = 1000;
    c->demo();
    int max = c->theMischbaresRezeptbuch->getNumberOfRecipes();
    int choice = 1;
    Recipe *r = c->theMischbaresRezeptbuch->getRecipe(choice - 1);

    EXPECT_GT(max, 0);
    EXPECT_EQ(r->m_Name, "Caipirinha");
}

TEST_F(CocktailProTest, choose_ok) {

    Timer::getInstance()->set_Turbo(2000);

    std::stringstream stringstream;
    stringstream.str("1");

    std::cin.rdbuf(stringstream.rdbuf());
    int choice = c->chooseCocktail();

    std::cin.clear();

    EXPECT_EQ(choice, 1);

}

TEST_F(CocktailProTest, exitProgramm) {
    Timer::getInstance()->set_Turbo(2000);

    std::stringstream stringstream;
    stringstream.str("-1");

    std::cin.rdbuf(stringstream.rdbuf());
    c->start();
    std::cin.clear();

    //to verify mocks are needed.

}
TEST_F(CocktailProTest, getCocktail){
    Recipe * r = NULL;
    EXPECT_EQ(r,c->getCocktail(10));
    EXPECT_EQ("Martini James B",c->getCocktail(8)->getName());
}

TEST_F(CocktailProTest, checkMischbar) {
    c->checkMischbar();
    for (int i=0; i < c->theMischbaresRezeptbuch->getNumberOfRecipes(); i++)
        EXPECT_TRUE(c->theMischbaresRezeptbuch->getRecipe(i)->isMischbar());

    Recipe* tmp = c->theMischbaresRezeptbuch->getRecipe(0);
    c->theCocktailZubereiter->cocktailZubereiten(tmp);
    c->theCocktailZubereiter->cocktailZubereiten(tmp);
    c->theCocktailZubereiter->cocktailZubereiten(tmp);
    c->theCocktailZubereiter->cocktailZubereiten(tmp);
    c->checkMischbar();
    EXPECT_FALSE(c->theMischbaresRezeptbuch->getRecipe(0)->isMischbar());
    delete tmp;
}