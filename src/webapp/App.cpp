//
// Created by vadim on 07.03.23.
//

#include "App.h"
#include "SqlReader.h"

App* App::_app = nullptr;
AppDestroyer App::_app_destroyer;

void AppDestroyer::initialize(App *app) {
    _app = app;
}

AppDestroyer::~AppDestroyer() {
    delete _app;
}

void App::load_bd() {
    auto db = drogon::app().getDbClient("database");
    auto dbreq = SqlReader::read("/home/vadim/programs/cpp/PacketManagerServer/migrations/db.sql");
    for (auto &com : dbreq) {
        db->execSqlSync(com);
    }
}

void App::init() {
    drogon::app()
            .registerBeginningAdvice(App::load_bd)
            .loadConfigFile("../server_config.json");
}

App *App::getInstance() {
    if (!_app) {
        _app = new App;
        _app_destroyer.initialize(_app);
        _app->init();
    }
    return _app;
}

void App::run() {
    drogon::app()
            .run();
}
