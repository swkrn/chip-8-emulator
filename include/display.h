#pragma once

#include <cstdint>

class Display {
    private:
        bool screen[64][32];

    public:
        void set(std::uint16_t x, std::uint16_t y, bool value);
        bool get(std::uint16_t x, std::uint16_t y);
        void clear();
};