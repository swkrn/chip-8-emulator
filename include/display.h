#pragma once

#include <cstdint>
#include "config.h"

class Display {
    private:
        bool screen[Config::SCREEN_WIDTH][Config::SCREEN_HEIGHT] = { false };

    public:
        void set(std::uint16_t x, std::uint16_t y, bool value);
        bool get(std::uint16_t x, std::uint16_t y);
        void clear();
};