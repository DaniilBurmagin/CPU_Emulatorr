#include "../include/Commands.hpp"

namespace Virtual_M {

    void PUSH::AddArg(const std::string& arg) {
        data = std::stoi(arg);
    }
    void PUSH::Realize(Stack<int>& stack, std::map<std::string, int>& list, CodeFile*& cur) {
        stack.push(data);
    }

    void PUSHR::AddArg(const std::string& arg) {
        regist = arg;
    }
    void PUSHR::Realize(Stack<int>& stack, std::map<std::string, int>& list, CodeFile*& cur) {
        int data = list.at(regist);
        stack.push(data);
    }

    void POP::Realize(Stack<int>& stack, std::map<std::string, int>& list, CodeFile*& cur) {
        stack.pop();
    }

    void POPR::AddArg(const std::string& arg) {
        regist = arg;
    }
    void POPR::Realize(Stack<int>& stack, std::map<std::string, int>& list, CodeFile*& cur) {
        int num = stack.top();
        list[regist] = num;
        stack.pop();
    }

    void ADD::Realize(Stack<int>& stack, std::map<std::string, int>& list, CodeFile*& cur) {
        int first_num = stack.top();
        stack.pop();
        int sum = stack.top() + first_num;
        stack.push(first_num);
        stack.push(sum);
    }

    void SUB::Realize(Stack<int>& stack, std::map<std::string, int>& list, CodeFile*& cur){
        int first_num = stack.top();
        stack.pop();
        int sub = first_num - stack.top();
        stack.push(first_num);
        stack.push(sub);
    }

    void MUL::Realize(Stack<int>& stack, std::map<std::string, int>& list, CodeFile*& cur) {
        int first_num = stack.top();
        stack.pop();
        int mul = first_num * stack.top();
        stack.push(first_num);
        stack.push(mul);
    }

    void DIV::Realize(Stack<int>& stack, std::map<std::string, int>& list, CodeFile*& cur) {
        int first_num = stack.top();
        stack.pop();
        int div = first_num / stack.top();
        stack.push(first_num);
        stack.push(div);
    }

    void OUT::Realize(Stack<int>& stack, std::map<std::string, int>& list, CodeFile*& cur) {
        int num = stack.top();
        std::cout << num << '\n';
        stack.pop();
    }

    void IN::Realize(Stack<int>& stack, std::map<std::string, int>& list, CodeFile*& cur) {
        int num;
        std::cin >> num;
        stack.push(num);
    }

    void JMP::AddArg(const std::string& arg) {
        label = arg;
    }
    void JMP::Realize(Stack<int>& stack, std::map<std::string, int>& list, CodeFile*& cur) {
        cur->LabelJump(label);
    }

    void JEQ::AddArg(const std::string& arg) {
        label = arg;
    }
    void JEQ::Realize(Stack<int> &stack, std::map<std::string, int> &list, CodeFile *&cur) {
        int val1 = stack.top();
        stack.pop();
        int val2 = stack.top();
        if (val1 == val2) {
            cur->LabelJump(label);
        }
        stack.push(val1);
    }

    void JNE::AddArg(const std::string& arg) {
        label = arg;
    }
    void JNE::Realize(Stack<int> &stack, std::map<std::string, int> &list, CodeFile *&cur) {
        int val1 = stack.top();
        stack.pop();
        int val2 = stack.top();
        if (val1 != val2) {
            cur->LabelJump(label);
        }
        stack.push(val1);
    }

    void JA::AddArg(const std::string& arg) {
        label = arg;
    }
    void JA::Realize(Stack<int> &stack, std::map<std::string, int> &list, CodeFile *&cur) {
        int val1 = stack.top();
        stack.pop();
        int val2 = stack.top();
        if (val1 > val2) {
            cur->LabelJump(label);
        }
        stack.push(val1);
    }

    void JAE::AddArg(const std::string& arg) {
        label = arg;
    }
    void JAE::Realize(Stack<int> &stack, std::map<std::string, int> &list, CodeFile *&cur) {
        int val1 = stack.top();
        stack.pop();
        int val2 = stack.top();
        if (val1 >= val2) {
            cur->LabelJump(label);
        }
        stack.push(val1);
    }

    void JB::AddArg(const std::string& arg) {
        label = arg;
    }
    void JB::Realize(Stack<int> &stack, std::map<std::string, int> &list, CodeFile *&cur) {
        int val1 = stack.top();
        stack.pop();
        int val2 = stack.top();
        if (val1 < val2) {
            cur->LabelJump(label);
        }
        stack.push(val1);
    }

    void JBE::AddArg(const std::string& arg) {
        label = arg;
    }
    void JBE::Realize(Stack<int> &stack, std::map<std::string, int> &list, CodeFile *&cur) {
        int val1 = stack.top();
        stack.pop();
        int val2 = stack.top();
        if (val1 <= val2) {
            cur->LabelJump(label);
        }
        stack.push(val1);
    }

    Command* CommandName(const std::string& str) {
        if (str == "begin") {
            return new BEGIN();
        }
        if (str == "end") {
            return new END();
        }
        if (str == "in") {
            return new IN();
        }
        if (str == "out") {
            return new OUT();
        }
        if (str == "push") {
            return new PUSH();
        }
        if (str == "pop") {
            return new POP();
        }
        if (str == "pushr") {
            return new PUSHR();
        }
        if (str == "popr") {
            return new POPR();
        }
        if (str == "add") {
            return new ADD();
        }
        if (str == "sub") {
            return new SUB();
        }
        if (str == "mul") {
            return new MUL();
        }
        if (str == "div") {
            return new DIV();
        }
        if (str == "jmp") {
            return new JMP();
        }
        if (str == "jeq") {
            return new JEQ();
        }
        if (str == "jne") {
            return new JNE();
        }
        if (str == "ja") {
            return new JA();
        }
        if (str == "jae") {
            return new JAE();
        }
        if (str == "jb") {
            return new JB();
        }
        if (str == "jbe") {
            return new JBE();
        }
        return nullptr;
    }
}