//@(#) CocktailZubereiter.h

#ifndef COCKTAILZUBEREITER_H_H
#define COCKTAILZUBEREITER_H_H



#include "Recipe.h"
#include "RecipeBook.h"
#include "DeviceVerwalter.h"

/**
 * @class CocktailZubereiter
 * @brief CocktailZubereiter makes the Cocktail according to the recipe steps
 *
 * it search in the recipe book the ingredients and add them to the cocktail step by step
 *  
 */
class CocktailZubereiter {
public:
    /**
     * @brief Constructor that a CocktailZubereiter
     *
     * it takes a DeviceVerwalter Pointer and makes it to a parameter
     * explicit does not allow type conversions
     * @param dv is a pointer to a DeviceVerwalter Class
     */
     explicit CocktailZubereiter(DeviceVerwalter * dv);
    /**
     * @brief waits for the cocktail to be made and prompts the recipe step
     *
     * it prompts the name of the chosen cocktail
     * the for loop takes step after step until the cocktail is finished
     * in the loop it creates a RecipeStep pointer and gets the current step
     * then it search for the zutat and the menge and prompts them
     * then it calls for the rezeptSchrittZubereiten of the myDeviceVerwalter Pointer and passes zutaten and menge
     * @param rzpt is pointer to the recipe that is being made
     * @return true when it has finished the cocktail
     */
    void cocktailZubereiten(Recipe * rzpt);

    /**
     * @brief checks the current quantity Status of Zutaten and prints it out
     * @param needToRefill counts how much Zutaten needs to be refilled, vector saves the string zutat for later usage
     * @param zutatenToRefill holds all ingredients that need to be refilled
     * @param recipe the recipe that is in production
     * internalDevice is needed for the actual quantity and receip * for menge
     */
    void checkZutatenStatus(int & needToRefill, std::vector<std::string> & zutatenToRefill, Recipe * recipe);

    /**
     * @brief checks if enough ingredients are available in Dosierer
     * @param zutat that is requested
     * @param benoetigteMenge amount of ingredient that is needed
     * @return bool if available amount >= need amount
     */
    bool enoughInDosiererFor(const std::string &zutat, float &benoetigteMenge) const;

private:
    /**
     * myDeviceVerwalter is a pointer to the DeviceVerwalter class
     * it is used for calling the rezeptSchrittZubereiten, entleeren and putzen method
     * */
    DeviceVerwalter * myDeviceVerwalter;


    /**
     * @brief modus in which the user has to confirm refillment
     * @param zutatenNeedToRefill contains all ingredients that need to be refilled
     */
    void refillModus(std::vector<std::string> &zutatenNeedToRefill);

    /**
     * @brief actually executes the Recipe
     * @param rzpt
     * @return all used devices
     */
    std::vector<InternalDevice *> executeRecipe(Recipe *rzpt) const;
};

#endif
