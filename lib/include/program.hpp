#pragma once
#include "Commands.hpp"
#include <vector>
#include <map>
#include <memory>
#include <string>

namespace Virtual_M {
    class CodeFile {
    private:
        bool flag = false;
        std::vector<std::shared_ptr<Command>> commands_;
        std::map<std::string, int> labels_;
        size_t StartIndex = 0;
        size_t FinishIndex = 0;
        size_t CurIndex = 0;
    public:
        void NewCommand(Command* str);
        void NewLabel(const std::string& lbl);
        void Compile();
        Command* ActualCommand();
        size_t GetCur() const {return CurIndex;};
        void LabelJump(const std::string& lbl);
        void IndexJump(size_t index);
    };
}