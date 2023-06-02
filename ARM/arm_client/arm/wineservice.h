#ifndef WINESERVICE_H
#define WINESERVICE_H

#include "wine.h"

class WineService
{
public:
    WineService();
    virtual std::vector<Wine> getAll() = 0;
    virtual ~WineService() = default;
};

#endif // WINESERVICE_H
