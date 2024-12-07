#pragma once

#include <cstdint>

class Register {
    private:
        std::uint8_t reg[16];

    public:
        void set(std::uint8_t position, std::uint8_t value);
        std::uint8_t get(std::uint8_t position);
};
