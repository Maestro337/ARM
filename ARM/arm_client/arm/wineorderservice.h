#ifndef WINEORDERSERVICE_H
#define WINEORDERSERVICE_H
#include <vector>
class WineOrderService
{
public:
    WineOrderService();
    virtual void orderByIds(const std::vector<int>& ids) = 0;
    virtual ~WineOrderService() = default;
};

#endif // WINEORDERSERVICE_H
