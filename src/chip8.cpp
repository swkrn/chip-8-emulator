#include "chip8.h"
#include "config.h"

#include <iostream>
#include <fstream>
#include <stdexcept>
#include <stdexcept>


Chip8::Chip8(const std::string &filename)
{
    mem.loadProgram(filename);
    pc = Config::START_PROGRAM_ADDRESS;
}

void Chip8::tick()
{
    std::uint16_t opcode = mem.get(pc);
    std::cout << "PC: " << std::dec << pc << ", OPCODE: " << std::hex << opcode << std::endl;
    bool isPcInc = execute(opcode);
    if (isPcInc)
    {
        pc += 2;
    }

    if (pc > 550) {
        throw std::runtime_error("Stop!");
    }
}

bool Chip8::execute(std::uint16_t opcode)
{
    if (opcode == 0x00E0)
    {
        screen.clear();
    }

    std::uint16_t t = opcode & 0xF000;
    std::uint16_t u = opcode & 0x000F;
    std::uint16_t x = (opcode & 0x0F00) >> 8;
    std::uint16_t y = (opcode & 0x00F0) >> 4;

    std::uint16_t nn = opcode & 0x00FF;
    std::uint16_t nnn = opcode & 0x0FFF;

    if (t == 0x1000) 
    {
        pc = nnn;
        return false;
    }

    if (t == 0x6000)
    {
        v.set(x, nn);
    }

    if (t == 0x7000)
    {
        uint16_t res = v.get(x) + nn;
        v.set(x, res);
    }

    if (t == 0x8000)
    {
        if (u == 0x0004)
        {
            uint16_t res = v.get(x) + v.get(y);
            if (res > 255)
            {
                v.set(0xF, 1);
            }
            else
            {
                v.set(0xF, 0);
            }
            v.set(x, res);
        }
    }

    if (t == 0xA000)
    {
        i = nnn;
    }
    return true;
}