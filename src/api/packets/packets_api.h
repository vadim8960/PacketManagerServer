//
// Created by vadim on 06.03.23.
//

#ifndef PACKETMANAGERSERVER_PACKETS_API_H
#define PACKETMANAGERSERVER_PACKETS_API_H

#include "drogon/HttpController.h"

using namespace drogon;

class packets_api : public drogon::HttpController<packets_api> {
public:
    METHOD_LIST_BEGIN
        METHOD_ADD(packets_api::get_packet_by_name, "/{1}", Get);
    METHOD_LIST_END

    void get_packet_by_name(const HttpRequestPtr &req,
                            std::function<void(const HttpResponsePtr &)> &&callback,
                            const std::string &name);
};

#endif //PACKETMANAGERSERVER_PACKETS_API_H
