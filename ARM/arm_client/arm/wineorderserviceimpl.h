#ifndef WINEORDERSERVICEIMPL_H
#define WINEORDERSERVICEIMPL_H
#include "wineorderservice.h"

class WineOrderServiceImpl : public WineOrderService
{
public:
    WineOrderServiceImpl();

    // WineOrderService interface
public:
    void orderByIds(const std::vector<int> &ids) override;
};

#endif // WINEORDERSERVICEIMPL_H
