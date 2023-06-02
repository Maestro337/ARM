#ifndef INGREDIENTSERVICE_H
#define INGREDIENTSERVICE_H

#include <vector>
#include "ingredient.h"

class IngredientService
{
public:
    IngredientService();
    virtual std::vector<Ingredient> getAll() = 0;
    virtual ~IngredientService() = default;
};

#endif // INGREDIENTSERVICE_H
