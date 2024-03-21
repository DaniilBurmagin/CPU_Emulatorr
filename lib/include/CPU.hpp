#pragma once
#include "Stack.hpp"
#include "program.hpp"
#include <map>
#include <iostream>

namespace Virtual_M {

    class CPU {
    private:
        Stack<int> stack_;
        std::map<std::string, int> rgstr_;
        CodeFile* current_ = nullptr;
    public:
        void ProgramExecution(CodeFile& Code);

    };
}