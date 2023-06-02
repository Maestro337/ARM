#ifndef INGREDIENTSERVICEIMPL_H
#define INGREDIENTSERVICEIMPL_H

#include "ingredientservice.h"

class IngredientServiceImpl : public IngredientService
{
public:
    IngredientServiceImpl();

    // IngredientService interface
public:
    std::vector<Ingredient> getAll();
};

#endif // INGREDIENTSERVICEIMPL_H
