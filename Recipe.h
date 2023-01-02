#ifndef _REZEPT_H_479
#define _REZEPT_H_479

#include "RecipeStep.h"

#include <list>
#include <string>
/**
 * @class Recipe
 * @brief encapsulates a recipe for a cocktail
 */
class Recipe {
private:
    /**
     * @brief a list of all the steps which is needed for the the recipe
     */
    std::list<RecipeStep*> m_RecipeStep;

    std::string m_Name;
    int m_Id;
    bool m_mischbar;

public:

    Recipe(void);

    ~Recipe();

    /**
     * returns number of recipe steps
     * @returns int
     *
     */
    int getNoOfRecipeSteps();

    /**
     *
     * @param i is an index to the recipe step
     * @return RecipeStep pointer
     */
    RecipeStep * getRecipeStep(unsigned int i);

    /**
     * returns name of the recipe
     *
     * @return  string
     */
    std::string getName(void) const;

    /**
     * returns id of the recipe
     *
     *  @return int
     */
     int getId(void) const;

    /**
     * sets the name of the recipe
     * @param Name
     */
    void setName(const std::string& Name);

    /**
     *
     * adds a new recipe step to the recipe step collection of recipe
     *
     * @param z
     * @param m
     */
    void appendStep(std::string z, float m);

    /**
     * displays Recipe's ID, name and every ingredient of the recipe
     */
    void browse();

    /**
     * @brief set the ID counter back to zero;
     */
    void setCounter();

    /**
     * @brief checks if recipe can be made
     * @return  bool
     */
    bool isMischbar();

    /**
     * @brief sets the recipe if it can be made
     * @param mischbar
     */
    void setMischbar(bool mischbar);
};

#endif
