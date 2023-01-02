
#include <algorithm>
#include <iostream>

#include "Recipe.h"


static int ctr = 0;
Recipe::Recipe(void) {
    m_RecipeStep.clear();
    m_Name = "";
    m_Id = ++ctr;
    m_mischbar = true;
}

Recipe::~Recipe() {
}

int Recipe::getNoOfRecipeSteps() {
    return (m_RecipeStep.size());
}

RecipeStep * Recipe::getRecipeStep(unsigned int i) {
    if (i > m_RecipeStep.size()) return NULL;
    else {
        std::list<RecipeStep*>::iterator p; // Iterator
        advance(p = m_RecipeStep.begin(), i); // p zeigt jetzt auf das i-te Element
        return (*p); // Adresse vom Wert von p - also den Pointer auf den der Iterator zeigt
    }
}

std::string Recipe::getName(void) const {
    return m_Name;
}

int Recipe::getId() const {
    return m_Id;
}

void Recipe::setName(const std::string& Name) {
    this->m_Name = Name;
}

void Recipe::browse() {
    std::cout << "[";
    if (this->isMischbar())
        std::cout << "✔";
    else
        std::cout << "X";
    std::cout << "] "<< m_Id << ". " << m_Name << ": ";
    for (int i = 0; i< this->getNoOfRecipeSteps(); i++) {
        if (i > 0) std::cout << ", ";
        std::cout << getRecipeStep(i)->getZutat();
    }
}

void Recipe::appendStep(std::string z, float m) {
    RecipeStep* t;
    t = new RecipeStep;
    t->setZutat(z);
    t->setMenge(m);
    m_RecipeStep.push_back(t);
}

void Recipe::setCounter() {
    ctr=0;
}

bool Recipe::isMischbar() {
    return m_mischbar;
}

void Recipe::setMischbar(bool mischbar) {
    m_mischbar = mischbar;
}