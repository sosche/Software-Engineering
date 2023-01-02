//@(#) MischbaresRezeptbuch.h

#ifndef MISCHBARESREZEPTBUCH_H_H
#define MISCHBARESREZEPTBUCH_H_H

#include "Recipe.h"
#include "RecipeBook.h"
#include "VorhandeneZutaten.h"

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib> // fuer exit() unter Linux

/**
 * @class MischbaresRezeptbuch
 * @brief knows all mixable Recipes and can find it or delete one
 * It can prompt the recipe or remove and delete a recipe
 * It inherits from RecipeBook
 *  
 */
class MischbaresRezeptbuch : public RecipeBook {
public:
    /**
     * @brief Standard constructor to provide test functions
     */
    MischbaresRezeptbuch();

    /**
     * @brief Constructor makes a MischbaresRezeptbuch by passing the VorhandeZutaten
     * @param ze is a pointer to VorhandeZutaten to know the ingredients it can use
     */
    explicit MischbaresRezeptbuch(VorhandeneZutaten * ze);

    /**
     * @brief browse prompts all mixable recipes that is currently has
     */
    void browse();

private:
    /**
     * is a pointer to VorhandeZutaten
     * it is used for knowing the ingredients it can use
     */
    VorhandeneZutaten * myZutatenVerwalter;

    /**
     * is a vector of recipes
     * it is used to store recipes to add it to the mixable recipe book
     */
    std::vector<Recipe *> rezepte;

    /**
     * @brief this method looks if the recipe exist and deletes it
     * it search through the recipe book and looks if all the ingredients for the recipe exist
     * if the ingredients aren't there it deletes the recipe and deletes it from the recipe book
     * if a recipe was deleted the loop is set back one
     */
    void seitenRausreissen();

    /**
     * @brief this method sets up a ZutatenVerwalter by passing a pointer of Vorhandene Zutaten
     */
    void setZutatenVerwalter(VorhandeneZutaten * ze);

    /**
     * @brief checks if needed ingredient is supplied
     * @param gesuchteZutat
     * @return true if gesuchteZutat exists
     */
    bool zutatExists(const std::string &gesuchteZutat) const;
};

#endif
