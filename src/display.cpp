#include "display.h"
#include "config.h"
#include <iostream>

void Display::set(std::uint16_t x, std::uint16_t y, bool value)
{
    screen[x][y] = value;
}

bool Display::get(std::uint16_t x, std::uint16_t y)
{
    return screen[x][y];
}

void Display::clear()
{
    for (int x = 0; x < Config::SCREEN_WIDTH; x++) 
    {
        for (int y = 0; y < Config::SCREEN_HEIGHT; y++) 
        {
            screen[x][y] = false;
        }
    }
}