#include <limits.h>
#include <string>
#include "gtest/gtest.h"


#define protected public
#define private public
#include "CocktailZubereiter.h"
#include "CocktailPro.h"
#undef protected
#undef private

class CocktailZubereiter_Test: public ::testing::Test
{
protected:
    DeviceVerwalter * deviceVerwalter;
    VorhandeneZutaten * vorhandeneZutaten;
    RecipeBook * recipeBook;
    CocktailZubereiter * cocktailZubereiter;
    int boost;

    virtual void SetUp()
    {
        boost=Timer::getInstance()->booster;
        vorhandeneZutaten = new VorhandeneZutaten();
        deviceVerwalter = new DeviceVerwalter(vorhandeneZutaten);
        recipeBook = new RecipeBook();
        cocktailZubereiter = new CocktailZubereiter(deviceVerwalter);
    }

    virtual void TearDown()
    {
        delete cocktailZubereiter;
        delete deviceVerwalter;
        delete vorhandeneZutaten;
        delete recipeBook;
        Timer::getInstance()->set_Turbo(boost);

    }
};

TEST_F(CocktailZubereiter_Test, CocktailzubereitenError)
{
    Timer * t = Timer::getInstance();
    Recipe *r;
    r = recipeBook->getRecipe(2);
    t->set_Turbo(100000);
    EXPECT_ANY_THROW(cocktailZubereiter->cocktailZubereiten(r));
}

TEST_F(CocktailZubereiter_Test, CocktailZubereitenOkay)
{
    Timer * t = Timer::getInstance();
    Recipe *r;
    r = recipeBook->getRecipe(1);
    t->set_Turbo(100000);
    EXPECT_NO_THROW(cocktailZubereiter->cocktailZubereiten(r));
}

TEST_F(CocktailZubereiter_Test, DosiererRunsEmtpy){

    Recipe * recipe= new Recipe;
    recipe->appendStep("Eis", 800);
    Timer::getInstance()->set_Turbo(1000);
    Dosierer* dosierer= dynamic_cast<Dosierer*> (cocktailZubereiter->myDeviceVerwalter->getDevices("Eis")[0]);
    std::stringstream stringstream;
    stringstream.str("1");

    std::cin.rdbuf(stringstream.rdbuf());

    cocktailZubereiter->cocktailZubereiten(recipe);
    EXPECT_EQ(dosierer->getMenge(), 200);
    cocktailZubereiter->cocktailZubereiten(recipe);
    std::cin.clear();
    EXPECT_EQ(dosierer->getMenge(),0);

}

TEST_F(CocktailZubereiter_Test, DosierRefill)
{
    std::vector<std::string> zutatenNeedToRefill;
    zutatenNeedToRefill.push_back("Limettenstuecke");
    std::stringstream stringisteami;

    stringisteami.str("1");
    std::cin.rdbuf(stringisteami.rdbuf());

    EXPECT_NO_THROW(cocktailZubereiter->refillModus(zutatenNeedToRefill););
}