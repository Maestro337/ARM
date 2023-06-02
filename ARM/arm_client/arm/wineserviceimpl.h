#ifndef WINESERVICEIMPL_H
#define WINESERVICEIMPL_H

#include <wineservice.h>
#include <set>

class WineServiceImpl : public WineService
{
public:
    WineServiceImpl();

    // WineService interface
public:
    std::vector<Wine> getAll();
};

#endif // WINESERVICEIMPL_H
