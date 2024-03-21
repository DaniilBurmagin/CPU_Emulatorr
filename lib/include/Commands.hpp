#pragma once
#include <string>
#include "CPU.hpp"

namespace Virtual_M {

    class CPU;

    class Command {
    public:
        virtual ~Command() {}

        virtual void Realize(Stack<int>& stack, std::map<std::string, int>& list, CodeFile*& cur) = 0;

        virtual void AddArg(const std::string& arg) {};
    };

    class BEGIN : public Command {
    public:
        void Realize(Stack<int>& stack, std::map<std::string, int>& list, CodeFile*& cur) override {};
    };

    class END : public Command {
    public:
        void Realize(Stack<int>& stack, std::map<std::string, int>& list, CodeFile*& cur) override {};
    };

    class PUSH : public Command {
    public:
        void Realize(Stack<int>& stack, std::map<std::string, int>& list, CodeFile*& cur) override;
        virtual void AddArg(const std::string& arg) override;
    private:
        int data;
    };

    class PUSHR : public Command {
    public:
        void Realize(Stack<int>& stack, std::map<std::string, int>& list, CodeFile*& cur) override;
        virtual void AddArg(const std::string& arg) override;
    protected:
        std::string regist;
    };

    class POP : public Command {
    public:
        void Realize(Stack<int>& stack, std::map<std::string, int>& list, CodeFile*& cur) override;
    };

    class POPR : public Command {
    public:
        void Realize(Stack<int>& stack, std::map<std::string, int>& list, CodeFile*& cur) override;
        virtual void AddArg(const std::string& arg) override;
    protected:
        std::string regist;
    };

    class IN : public Command {
    public:
        void Realize(Stack<int>& stack, std::map<std::string, int>& list, CodeFile*& cur) override;
    };

    class OUT : public Command {
    public:
        void Realize(Stack<int>& stack, std::map<std::string, int>& list, CodeFile*& cur) override;
    };

    class ADD : public Command {
    public:
        void Realize(Stack<int>& stack, std::map<std::string, int>& list, CodeFile*& cur) override;
    };

    class SUB : public Command {
    public:
        void Realize(Stack<int>& stack, std::map<std::string, int>& list, CodeFile*& cur) override;
    };

    class MUL : public Command {
    public:
        void Realize(Stack<int>& stack, std::map<std::string, int>& list, CodeFile*& cur) override;
    };

    class DIV : public Command {
    public:
        void Realize(Stack<int>& stack, std::map<std::string, int>& list, CodeFile*& cur) override;
    };

    class JMP : public Command {
    public:
        void Realize(Stack<int>& stack, std::map<std::string, int>& list, CodeFile*& cur) override;
        virtual void AddArg(const std::string& arg) override;
    protected:
        std::string label;
    };

    class JEQ : public Command {
    public:
        void Realize(Stack<int>& stack, std::map<std::string, int>& list, CodeFile*& cur) override;
        virtual void AddArg(const std::string& arg) override;
    protected:
        std::string label;
    };

    class JNE : public Command {
    public:
        void Realize(Stack<int>& stack, std::map<std::string, int>& list, CodeFile*& cur) override;
        virtual void AddArg(const std::string& arg) override;
    protected:
        std::string label;
    };

    class JA : public Command {
    public:
        void Realize(Stack<int>& stack, std::map<std::string, int>& list, CodeFile*& cur) override;
        virtual void AddArg(const std::string& arg) override;
    protected:
        std::string label;
    };

    class JAE : public Command {
    public:
        void Realize(Stack<int>& stack, std::map<std::string, int>& list, CodeFile*& cur) override;
        virtual void AddArg(const std::string& arg) override;
    protected:
        std::string label;
    };

    class JB : public Command {
    public:
        void Realize(Stack<int>& stack, std::map<std::string, int>& list, CodeFile*& cur) override;
        virtual void AddArg(const std::string& arg) override;
    protected:
        std::string label;
    };

    class JBE : public Command {
    public:
        void Realize(Stack<int>& stack, std::map<std::string, int>& list, CodeFile*& cur) override;
        virtual void AddArg(const std::string& arg) override;
    protected:
        std::string label;
    };
    Command* CommandName(const std::string& str);
}