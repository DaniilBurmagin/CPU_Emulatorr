#pragma once
#include "program.hpp"
#include "Commands.hpp"
#include <string>
#include <fstream>
#include <unordered_map>


namespace Virtual_M {

    class Parser {
        std::unordered_map<std::string, std::vector<std::shared_ptr<Command>>> func;
    public:
        CodeFile ParserCode(const char* path);

        CodeFile MainParser(std::ifstream& FILE, CodeFile* program);

    };
}