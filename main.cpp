#include <drogon/drogon.h>

using namespace drogon;

typedef std::function<void(const HttpResponsePtr &)> Callback;

void indexHandler(const HttpRequestPtr &request, Callback &&callback) {
    Json::Value jsonBody;
    jsonBody["message"] = "Hello, world";

    auto response = HttpResponse::newHttpJsonResponse(jsonBody);
    callback(response);
}

int main() {
    app()
            .loadConfigFile("../configs/test_config.json")
            .registerHandler("/", &indexHandler, {Get})
            .run();

    return EXIT_SUCCESS;
}