#include "storage.h"



Storage::Storage(const Wine &wine, const int &count):
    wine(wine),
    count(count)
{

}

const Wine &Storage::getWine() const
{
    return wine;
}

const int &Storage::getCount() const
{
    return this->count;
}
