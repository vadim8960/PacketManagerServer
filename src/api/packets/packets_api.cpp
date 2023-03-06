//
// Created by vadim on 06.03.23.
//

#include "packets_api.h"
#include "SqlReader.h"

void v1::User::test(const drogon::HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback,
                          const std::string &val) {
    auto db = app().getDbClient("database");


    auto dbreq = SqlReader::readSqlScript("/home/vadim/programs/cpp/PacketManagerServer/migrations/db.sql");

    for (auto &com : dbreq) {
        db->execSqlSync(com);
    }

    auto db_res = db->execSqlSync("select * from _packets;");

    Json::Value retv;
    Json::Value jrow;
    for (auto &row: db_res) {
        jrow["id"] = row["id"].as<int>();
        jrow["data"] = row["path"].as<std::string>();
        jrow["token"] = drogon::utils::getUuid();
        retv["data"].append(jrow);
    }
    retv["result"] = "ok";
    retv["token"] = drogon::utils::getUuid();

    auto resp = HttpResponse::newHttpJsonResponse(retv);
    callback(resp);
}