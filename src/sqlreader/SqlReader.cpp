//
// Created by vadim on 06.03.23.
//

#include "SqlReader.h"
#include <fstream>
#include <iostream>

std::vector<std::string> SqlReader::read(const std::string &script_path) {
    std::ifstream in(script_path);
    if (!in.is_open()) throw std::runtime_error("Error! Can't open file" + script_path);
    std::vector<std::string> res;
    std::string fullcmd;
    for (std::string line; std::getline(in, line); ) {
        if (!line.empty()) {
            fullcmd += line;
            if (*(fullcmd.end() - 1) == ';') {
                res.push_back(fullcmd);
                fullcmd.clear();
            }
        }
    }
    return res;
}