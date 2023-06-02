#ifndef MIXORDERSERVICE_H
#define MIXORDERSERVICE_H
#include <vector>

class MixOrderService
{
public:
    MixOrderService();
    virtual void orderByIds(const std::vector<int>& ids) = 0;
    virtual ~MixOrderService() = default;
};

#endif // MIXORDERSERVICE_H
