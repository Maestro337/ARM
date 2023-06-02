#include "ingredient.h"


Ingredient::Ingredient(const int &id, const std::string &name, const int &price):
    id(id),
    name(name),
    price(price)
{

}

const int &Ingredient::getId() const
{
    return this->id;
}

const std::string &Ingredient::getName() const
{
    return this->name;
}

const int &Ingredient::getPrice() const
{
    return this->price;
}
