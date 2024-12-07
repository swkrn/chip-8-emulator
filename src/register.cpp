#include "register.h"

void Register::set(std::uint8_t position, std::uint8_t value)
{
    reg[position] = value;
}

std::uint8_t Register::get(std::uint8_t position)
{
    return reg[position];
}
