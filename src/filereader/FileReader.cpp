//
// Created by vadim on 07.03.23.
//

#include "FileReader.h"
#include <fstream>

Line FileReader::read(const std::string &path) {
    std::ifstream in(path, std::ios::binary | std::ios::in);
    if (!in.is_open()) throw std::runtime_error("Error! Can't open file" + path);
    Line res;
    for (std::string line; std::getline(in, line); res += line);
    return res;
}

std::vector<Line> FileReader::readlines(const std::string &path) {
    std::ifstream in(path, std::ios::binary | std::ios::in);
    if (!in.is_open()) throw std::runtime_error("Error! Can't open file" + path);
    std::vector<Line> res;
    for (std::string line; std::getline(in, line); res.push_back(line));
    return res;
}
