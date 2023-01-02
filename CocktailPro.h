//@(#) CocktailPro.h

#ifndef COCKTAILPRO_H_H
#define COCKTAILPRO_H_H



#include "DeviceVerwalter.h"
#include "VorhandeneZutaten.h"
#include "MischbaresRezeptbuch.h"
#include "CocktailZubereiter.h"

/**
 * Gesamtsystem
 *
 */
/**
 * @class CocktailPro
 *
 * @brief CocktailPro manages the making of a cocktail
 *
 * A CocktialPro class has pointers to CocktailZubereiter, DeviceVerwalter, MischbaresRezeptbuch, VorhandeneZutaten
 * It has an int chooseCocktail that indicates the Cocktail that was chosen
 * the demo function makes the first cocktail of the recipe book
 * the start function starts the mixing process for a specific cocktail
 *
 */
class CocktailPro {
private:
    /**
     * theCocktailZubereiter is a pointer to the class CocktailZubereiter
     * it is used for managing the CocktailZubereiter class
     */

    CocktailZubereiter * theCocktailZubereiter;

    /**
    * theDeviceVerwalter is a pointer to the class DeviceVerwalter
    * it is used for managing the DeviceVerwalter class
    */

    DeviceVerwalter * theDeviceVerwalter;

    /**
    * theMischbaresRezeptbuch is a pointer to the class MischbaresRezeptbuch
    * it is used for managing the MischbaresRezeptbuch class to get the ingredients necessary for the cocktail
    */

    MischbaresRezeptbuch * theMischbaresRezeptbuch;

    /**
    * theZutatenVerwalter is a pointer to the class VorhandeneZutaten
    * it is used for managing the VorhandeneZutaten class
    */

    VorhandeneZutaten * theZutatenVerwalter;

protected:
    /**
     * @brief shows all cocktails and lets the user choose one
     * @returns an integer representing the chosen cocktail
     * */
    int chooseCocktail();
    /**
     * @brief starts the mixing of the first recipe in the recipebook
     * it sets the chooseCocktail Variable to 1
     * it proves if a recipe number 1 exist and
     * calls the cocktailZubereiten method by passing the recipe number
     */
    void demo();

public:
    /**
     * @brief Constructor that creates a Cocktail Pro Machine
     *
     * It declares pointers to classes of CocktailZubereiter, DeviceVerwalter, MischbaresRezeptbuch, VorhandeneZutaten
     * it also sets the timer
     * @param argc
     * @param turbo char to check if booster should be activated, if so it sets the timer to 1000
     */
    CocktailPro(int argc, char * * turbo);

    /**
     * @brief Copy Constructor
     */
    CocktailPro(CocktailPro& copy);

    /**
     * @brief starts the cocktail selection and then mixing process
     *
     * it prompts all mixable Cocktails and then ask for the number of the recept it should mix
     * then it proves if the number exist
     * if so it makes a pointer to the recipe
     * then it calls the cocktialZubereiten method and passes the recipe pointer
     * if the number doesn't exist it prompts all mixable cocktails again
     */
    void start();

    /**
     * @brief returns the recipe according to the id
     * @param i is the id which is used for searching for the recipe
     * @return the recipe which matches the the id
     */
    Recipe* getCocktail(int i);

    /**
     * @brief goes through all recipes from MischbaresRezeptbuch and checks Dosierer, sets Recipe flags
     *
     */
    void checkMischbar();

    /**
     * @brief destructor to safely delete memory usage
     */
    virtual ~CocktailPro();


};

#endif
