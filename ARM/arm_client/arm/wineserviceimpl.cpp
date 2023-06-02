#include "wineserviceimpl.h"
#include <cpr/cpr.h>
#include <nlohmann/json.hpp>
#include <string>
#include <QString>
#include <QDebug>

WineServiceImpl::WineServiceImpl()
{

}

std::vector<Wine> WineServiceImpl::getAll()
{
    auto response = cpr::Get(cpr::Url{"http://localhost:8080/api/storage/getAll"});
    nlohmann::json j = nlohmann::json::parse(response.text);
//    qDebug() << j[0]["count"].get<int>();

    std::vector<Wine> res;
    for (int i = 0; i < j.size(); ++i) {
        if (j[i]["count"].get<int>() >=1) {

            auto wine = j[i]["wine"];
            int wineId = wine["id"].get<int>();
            std::string wineName = wine["name"].get<std::string>();
            int winePrice = wine["price"].get<int>();
            std::set<std::string> wineAttrs;
//            wineAttrs.reserve(wine["attributeSet"].size());
            for (int i = 0; i < wine["attributeSet"].size(); ++i) {
                wineAttrs.insert(wine["attributeSet"][i]["name"].get<std::string>());
            }
            res.push_back(Wine(wineId,wineName,winePrice,wineAttrs));
        }
    }
    qDebug() << QString::fromStdString(response.text);
    return res;
}
