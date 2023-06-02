#ifndef WINE_H
#define WINE_H

#include <string>
#include <set>
#include <vector>

class Wine
{
public:
    Wine() = delete;

    Wine(const int& id,const std::string& name, const int& price,const std::set<std::string>& properties);

    const int& getId() const;
    const std::string& getName() const;
    const int& getPrice() const;
    const std::set<std::string>& getProperties() const;

private:
    int id;
    std::string name;
    int price;
    std::set<std::string> properies;
};

#endif // WINE_H
