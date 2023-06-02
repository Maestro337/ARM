#include "ingredientserviceimpl.h"
#include <string>
#include <QString>
#include <QDebug>
#include <cpr/cpr.h>
#include <nlohmann/json.hpp>


IngredientServiceImpl::IngredientServiceImpl()
{

}

std::vector<Ingredient> IngredientServiceImpl::getAll()
{

    std::vector<Ingredient> res;
    auto response = cpr::Get(cpr::Url{"http://localhost:8080/api/ingredient/getAll"});
    qDebug() << QString::fromStdString(response.text);
    auto j = nlohmann::json::parse(response.text);

    for (int i = 0; i < j.size(); ++i) {
        auto id = j[i]["id"].get<int>();
        auto name = j[i]["name"].get<std::string>();
        auto price = j[i]["price"].get<int>();
        auto ingredient = Ingredient(id,name,price);
        res.push_back(ingredient);
    }

    return res;
}
