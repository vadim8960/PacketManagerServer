//
// Created by vadim on 06.03.23.
//

#ifndef PACKETMANAGERSERVER_SQLREADER_H
#define PACKETMANAGERSERVER_SQLREADER_H

#include <string>
#include <vector>

class SqlReader {
public:
    static std::vector<std::string> read(const std::string& script_path);
};


#endif //PACKETMANAGERSERVER_SQLREADER_H
