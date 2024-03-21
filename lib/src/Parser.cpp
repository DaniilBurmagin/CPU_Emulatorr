#include "../include/Parser.hpp"
#include <fstream>
#include <string>



namespace Virtual_M {

    CodeFile Parser::MainParser(std::ifstream& file, CodeFile* program){
        std::string Name;
        std::string str;
        while(std::getline(file, str)) {
            if
            str = str.substr(1);
        }
        Command* command = CommandName(Name);
        std::string arg;
        command->AddArg(arg);
        program->NewCommand(command);
    }

    CodeFile Parser::ParserCode(const char* path){
        std::ifstream file;
        file.open(path);
        CodeFile program;

        std::string str;
        std::string func_name;

        while(std::getline(file, str)) {
            if (str[0] == '\t') {
                str = str.substr(1);
                func[func_name].emplace_back(CommandName(str));
            }
            else {
                if (str == "begin") {
                    MainParser(file, &program);
                }
                str.resize(str.size() - 1);
                func[str];
            }
        }

        return program;



    }
}