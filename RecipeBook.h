#ifndef RECIPEBOOK_H_489
#define RECIPEBOOK_H_489

#include <fstream>
#include <sstream>

#include <cstdlib> // fuer exit() unter Linux

#include <iostream>

#include <list>
#include <string>

#include "Recipe.h"

/**
 * @class RecipeBook
 *
 * @brief RecipeBook manages a collection of recipes
 *
 * A RecipeBook knows a list of recipes
 * You can ask for the number of recipes, query recipes by index
 * or delete a recipe
 *
 */
class RecipeBook {
    /**
    * This is the list of recipes that the RecipeBook manages
    *
    */
  private:
    std::list<Recipe *> m_Recipe;

  public:
    /** @brief Construktor that creates a RecipeBook
    * @return A pointer to the created RecipeBook
    *
    * This method creates a RecipeBook.
    * It uses temporarily an object of the class Initialisierer
    * to initialize the list of recipes. After that the
    * Initialisierer is destroyed.
    */
    RecipeBook(void);

    /** @brief Destructor that deletes the RecipeBook
     * it clears the recipe book vector
    */
    virtual ~RecipeBook();

    /** @brief Returns the number of recipes
    * @return The number of recipes in the RecipeBook
    */
    int getNumberOfRecipes();

    /** @brief fetches the i-th recipe
    * @param [in] i a positive integer for the i-th recipe
    * @return A pointer to the requested recipe object, NULL for invalid i
    *
    * This method returns the i-th recipe;
    * where i is an integer from 0 to n-1
    * where n is the number of recipes in the RecipeBook
    */
    Recipe * getRecipe(unsigned int i);

    /** @brief Deletes the i-th recipe from the RecipeBook
    * @param [in] i a positive integer for the i-th recipe
    * @return Boolean that indicates whether the deletion was successful
    *
    * This method deletes the i-th recipe from the RecipeBook.
    * And returns true if the deletion was successful (valid i).
    * For values of i that are invalid (i <0 or i>=n) the function return false.
    */
    bool deleteRecipe(unsigned int i);

    /**
     * @brief this method initialize the standard cocktails that the cocktail maker can make
     * it calls standardrecipes method in case no input file could be opened
     */
    void makestandardrecipes();

    /**
     * @brief the method adds standard recipes to m_Recipe
     * it declares a pointer of a recipe
     * the pointer refers to a new recipe
     * the recipe name is added
     * the first step is added with the ingredient and the time it takes
     * the next step is added till there are no more steps
     * the recipe is pushed into the vector of m_Recipes
     * the next recipe is added in the same way as the first one
     * 8 recipe will be added to the vector which each cocktail
     * has different process steps
     */
    void standardrecipes();

    /**
     * @brief it opens a file of recipes
     * it search at the located path for the file with the given name and opens it
     * @return it return the opened file
     */

    std::ifstream opennewrecipebookfile();


};

#endif
