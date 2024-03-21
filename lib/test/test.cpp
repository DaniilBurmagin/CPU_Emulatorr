#include "../include/Stack.hpp"
#include <string>
#include <gtest/gtest.h>

using namespace Virtual_M;

TEST(TestOfStack, CommandsPushPop) {
    Stack<int> test_stack;
    test_stack.push(3);
    test_stack.push(2);
    test_stack.push(1);

    for (size_t i = 1; i < 4; i++) {
        EXPECT_EQ(test_stack.top(), i);
        test_stack.pop();
    }
}

TEST(TestOfStack, CopyStack) {
    Stack<int> FirstStack;
    for (int i = 10; i > 0; i--) {
        FirstStack.push(i);
    }

    Stack<int> SecondStack(FirstStack);
    for (int i = 1; i < 11; i++) {
        EXPECT_EQ(SecondStack.top(), i);
        SecondStack.pop();
    }

    Stack<int> ThirdStack;
    ThirdStack = FirstStack;
    for (int i = 1; i < 11; i++) {
        EXPECT_EQ(ThirdStack.top(), i);
        ThirdStack.pop();
    }

    for (int i = 0; i < 20; i++) {
        ThirdStack.push(1);
    }
    ThirdStack = FirstStack;
    for (int i = 1; i < 11; i++) {
        EXPECT_EQ(ThirdStack.top(), i);
        ThirdStack.pop();
    }


}