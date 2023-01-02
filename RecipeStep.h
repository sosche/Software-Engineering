#ifndef _REZEPTSCHRITT_H_472
#define _REZEPTSCHRITT_H_472

#include <list>
#include <string>

/**
 * @class RecipeStep
 * @brief encapsulates a step of the whole Recipe
 */
class RecipeStep {

    std::string m_Zutat;

    float m_Menge;

public:

    RecipeStep(void);

    ~RecipeStep();
/**
 * returns the ingredient name
 * @return string
 */
    std::string getZutat(void) const;

    /**
     * returns the amount of the ingredient
     * @return float
     */
    float getMenge(void) const;

    /**
     * sets an ingredient
     * @param m_Zutat
     */
    void setZutat(std::string m_Zutat);

    /**
     * sets the amount of the ingredient
     * @param m_Menge
     */
    void setMenge(float m_Menge);

};
#endif
