#ifndef STORAGESERVICE_H
#define STORAGESERVICE_H

#include <storage.h>
#include <vector>


class StorageService
{
public:
    StorageService();
    virtual std::vector<Storage> getAll() = 0;
    virtual ~StorageService() = default;
};

#endif // STORAGESERVICE_H
