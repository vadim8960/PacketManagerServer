//
// Created by vadim on 06.03.23.
//

#ifndef PACKETMANAGERSERVER_PACKETS_API_H
#define PACKETMANAGERSERVER_PACKETS_API_H

#include "drogon/HttpController.h"

using namespace drogon;

namespace v1 {
    class User : public drogon::HttpController<User> {
    public:
        METHOD_LIST_BEGIN
            METHOD_ADD(User::test, "/{1}", Get);
        METHOD_LIST_END

        void test(const HttpRequestPtr &req,
                  std::function<void(const HttpResponsePtr &)> &&callback,
                  const std::string &val);
    };
}

#endif //PACKETMANAGERSERVER_PACKETS_API_H
