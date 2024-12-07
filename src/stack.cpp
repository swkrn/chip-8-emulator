#include "stack.h"

void Stack::push(std::uint16_t value)
{
    stack.push_back(value);
}

std::uint16_t Stack::pop()
{
    std::uint16_t last = stack.back();
    stack.pop_back();
    return last;
}