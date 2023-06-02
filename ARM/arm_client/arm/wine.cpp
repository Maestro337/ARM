#include "wine.h"


Wine::Wine(const int& id,const std::string &name, const int &price, const std::set<std::string> &properties) :
    id(id),
    name(name),
    price(price),
    properies(properties)
{
}

const int &Wine::getId() const
{
    return this->id;
}

const std::string &Wine::getName() const
{
    return this->name;
}

const int &Wine::getPrice() const
{
    return this->price;
}

const std::set<std::string> &Wine::getProperties() const
{
    return this->properies;
}
