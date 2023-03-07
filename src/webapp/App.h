//
// Created by vadim on 07.03.23.
//

#ifndef PACKETMANAGERSERVER_APP_H
#define PACKETMANAGERSERVER_APP_H

#include <drogon/drogon.h>
#include "packets_api.h"

class App;

class AppDestroyer {
private:
    App *_app;
public:
    void initialize(App *app);

    ~AppDestroyer();
};


class App {
private:
    static App *_app;
    static AppDestroyer _app_destroyer;
private:
    App() = default;

    App(const App &) = default;

    App &operator=(App &) = default;

    static void load_bd();

    void init();

public:
    friend class AppDestroyer;

    static App *getInstance();

    void run();
};


#endif //PACKETMANAGERSERVER_APP_H
