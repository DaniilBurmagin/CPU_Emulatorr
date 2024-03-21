#include <iostream>
#include "./lib/include/Parser.hpp"
#include "./lib/include/CPU.hpp"

using namespace Virtual_M;

int main() {
    std::cout << "Hello, World!" << std::endl;
    char* path = "FILES/def1.txt";
    Parser parser;
    CPU proc;
    CodeFile prog = parser.ParserCode(path);
    proc.ProgramExecution(prog);
    return 0;
}
