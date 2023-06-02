#include "wineorderserviceimpl.h"
#include <nlohmann/json.hpp>
#include <cpr/cpr.h>

WineOrderServiceImpl::WineOrderServiceImpl()
{

}

void WineOrderServiceImpl::orderByIds(const std::vector<int> &ids)
{
    nlohmann::json j = ids;
    cpr::Post(cpr::Url{"http://localhost:8080/api/storage/purchase"},
              cpr::Body{j.dump()},
              cpr::Header{{"Content-Type", "application/json"}});
}
