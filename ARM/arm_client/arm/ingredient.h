#ifndef INGREDIENT_H
#define INGREDIENT_H

#include <string>

class Ingredient
{
public:
    Ingredient() = delete;
    Ingredient(const int& id, const std::string& name, const int& price);
    const int& getId() const;
    const std::string& getName() const ;
    const int& getPrice() const;

private:
    int id;
    std::string name;
    int price;

};

#endif // INGREDIENT_H
