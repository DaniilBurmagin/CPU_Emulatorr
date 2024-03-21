#include "../include/CPU.hpp"

namespace Virtual_M {

    void CPU::ProgramExecution(CodeFile &Code) {
        Code.Compile();
        current_ = &Code;
        Command* actual = Code.ActualCommand();
        while(actual != nullptr) {
            actual->Realize(stack_, rgstr_, current_);
            actual = Code.ActualCommand();
        }
        current_ = nullptr;
    }
}