#ifndef MIXORDERSERVICEIMPL_H
#define MIXORDERSERVICEIMPL_H

#include "mixorderservice.h"

class MixOrderServiceImpl : public MixOrderService
{
public:
    MixOrderServiceImpl();

    // MixOrderService interface
public:
    void orderByIds(const std::vector<int> &ids);
};

#endif // MIXORDERSERVICEIMPL_H
