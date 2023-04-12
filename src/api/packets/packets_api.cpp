//
// Created by vadim on 06.03.23.
//

#include "packets_api.h"
#include "SqlReader.h"
#include "FileReader.h"
#include "base64.hpp"

void packets_api::get_packet_by_name(const drogon::HttpRequestPtr &req,
                                     std::function<void(const HttpResponsePtr &)> &&callback,
                                     const std::string &name) {

    auto db = drogon::app().getDbClient("database");
    auto db_res = db->execSqlSync("select path from _packets where name=$1;", name);

    Json::Value retv;

    std::vector<std::string> libs;
    for (auto &row: db_res)
        libs.push_back(row["path"].as<std::string>());

    if (libs.empty()) {
        Json::Value empty;
        auto resp = HttpResponse::newHttpJsonResponse(empty);
        resp->setStatusCode(drogon::k404NotFound);
        callback(resp);
        return;
    }

    retv["data"] = base64::to_base64(FileReader::read(libs[0]));


    auto resp = HttpResponse::newHttpJsonResponse(retv);
    callback(resp);
}