#ifndef STORAGE_H
#define STORAGE_H

#include "wine.h"

class Storage
{
public:
    Storage() = delete;
    Storage(const Wine& wine, const int& count);

    const Wine& getWine() const;
    const int& getCount() const;

private:
    Wine wine;
    int count;

};

#endif // STORAGE_H
