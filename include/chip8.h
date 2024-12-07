#pragma once

#include <iostream>
#include <cstdint>

#include "mem.h"
#include "display.h"
#include "register.h"
#include "stack.h"
#include "timer.h"

class Chip8 {
    private:
        std::uint16_t pc;
        std::uint16_t i;

        Mem mem;
        Display screen;
        Register v;
        Stack stack;
        Timer timer;

        bool execute(std::uint16_t opcode);

    public:
        Chip8(const std::string& filename);
        void tick();
};
