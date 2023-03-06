#include "drogon/drogon.h"
#include "drogon/orm/DbClient.h"
#include "packets_api.h"

using namespace drogon;
using namespace drogon::orm;

int main() {
    app()
            .loadConfigFile("../server_config.json")
            .run();
    return EXIT_SUCCESS;
}
