#include "mem.h"
#include "config.h"
#include <iostream>
#include <fstream>
#include <stdexcept>



Mem::Mem()
{
    loadFont();
}

void Mem::loadFont()
{
    for (int i = 0; i < Config::FONT_AMOUNT; i++) 
    {
        for (int k = 0; k < Config::FONT_SIZE; k++) 
        {
            mem[Config::START_FONT_ADDRESS + (i * Config::FONT_AMOUNT) + k] = Config::FONT[i][k];
        }
    }
}

void Mem::set(std::uint16_t position, std::uint8_t value)
{
    mem[position] = value;
}


std::uint16_t Mem::get(std::uint16_t pc)
{
    return (mem[pc] << 8) + mem[pc + 1];
}

void Mem::loadProgram(const std::string &filename)
{
    std::ifstream file(filename, std::ios::binary);
    if (!file) 
    {
        throw std::runtime_error("Error opening file: " + filename);
    }

    file.seekg(0, std::ios::end);
    std::streamsize size = file.tellg();
    file.seekg(0, std::ios::beg);

    if (file.read(reinterpret_cast<char*>(mem + Config::START_PROGRAM_ADDRESS), size))
    {
        std::cout << "Program loaded successfully!" << std::endl;
    } 
    else 
    {
        throw std::runtime_error("Error reading file: " + filename);
    }
    file.close();
}