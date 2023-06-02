#ifndef STORAGESERVICEIMPL_H
#define STORAGESERVICEIMPL_H

#include <storageservice.h>

class StorageServiceImpl : public StorageService
{
public:
    StorageServiceImpl();

    // StorageService interface
public:
    std::vector<Storage> getAll() override;
};

#endif // STORAGESERVICEIMPL_H
