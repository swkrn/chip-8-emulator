#pragma once

#include <cstdint>
#include "config.h"
#include <iostream>

class Mem {
    private:
        std::uint8_t mem[Config::MEM_SIZE] = {0};
        void loadFont();

    public:
        Mem();

        void set(std::uint16_t address, std::uint8_t value);
        std::uint16_t get(std::uint16_t address);

        void loadProgram(const std::string &filename);
};