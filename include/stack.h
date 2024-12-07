#pragma once

#include <cstdint>
#include <vector>

class Stack {
    private:
        std::vector<std::uint16_t> stack;

    public:
        void push(std::uint16_t value);
        std::uint16_t pop();
};