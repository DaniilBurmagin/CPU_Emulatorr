#pragma once
#include <iostream>
#include <string>
#include <cstddef>
#include <cstdint>
#include <cstdbool>

namespace Virtual_M {
    template<class T = int>
    class Stack {
    private:
        size_t size_;
        size_t capacity_;
        T *value_;

        void Realloc() {
            T* new_value = new T[capacity_ * 2];
            for (size_t i = 0; i < size_; i++) {
                new_value[i] = value_[i];
            }
            delete[] value_;
            value_ = new_value;
            capacity_ *= 2;
        }

    public:
        Stack() : size_(0), capacity_(5), value_(new T[capacity_]) {}

        Stack(const Stack &other) :
                size_(other.size_),
                capacity_(other.capacity_),
                value_(new T[capacity_]) {
            for (size_t i = 0; i < size_; i++) {
                value_[i] = other.value_[i];
            }
        }

        ~Stack() { delete[] value_; }

        Stack(Stack &&other) :
                size_(other.size_),
                capacity_(other.capacity_),
                value_(other.value_) {
            other.value_ = nullptr;
        }

        Stack &operator=(const Stack &other) {
            if (this == &other) {
                return *this;
            }
            T *new_value = new T[other.capacity_];
            for (size_t i = 0; i < other.size_; i++) {
                new_value[i] = other.value[i];
            }
            delete[] value_;
            value_ = new_value;
            capacity_ = other.capacity_;
            size_ = other.size_;
            return *this;
        }

        Stack &operator=(Stack &&other) noexcept {
            if (this == &other) {
                return *this;
            }
            delete[] value_;
            value_ = other.value;
            size_ = other.size_;
            capacity_ = other.capacity_;
            other.value_ = nullptr;
            return *this;
        }

        void push(const T& data) {
            if (size_ == capacity_) {
                Realloc();
            }
            value_[size_++] = data;
        }

        void push(T&& data) {
            if (size_ == capacity_) {
                Realloc();
            }
            value_[size_++] = std::move(data);
        }

        void pop() {
            size_--;
        }

        T& top() const {
            return value_[size_ - 1];
        }

    };
}