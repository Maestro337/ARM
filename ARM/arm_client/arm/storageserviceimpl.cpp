#include "storageserviceimpl.h"
#include "wine.h"
#include <cpr/cpr.h>
#include <nlohmann/json.hpp>

StorageServiceImpl::StorageServiceImpl()
{

}

std::vector<Storage> StorageServiceImpl::getAll()
{
    auto response = cpr::Get(cpr::Url{"http://localhost:8080/api/storage/getAll"});
    auto j = nlohmann::json::parse(response.text);
    std::vector<Storage> res;

    for (int i = 0; i < j.size(); ++i) {
        int count = j[i]["count"];
        auto wine = j[i]["wine"];

        int wineId = wine["id"].get<int>();
        std::string wineName = wine["name"].get<std::string>();
        int winePrice = wine["price"].get<int>();
        std::set<std::string> wineAttrs;
        for (int i = 0; i < wine["attributeSet"].size(); ++i) {
            wineAttrs.insert(wine["attributeSet"][i]["name"].get<std::string>());
        }
        res.push_back(Storage(Wine(wineId,wineName,winePrice,wineAttrs),count));
    }

    return res;
}
