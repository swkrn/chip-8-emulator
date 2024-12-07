#include <iostream>

#include "chip8.h"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cout << "Only 1 argument: filename" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    Chip8 chip8 = Chip8(filename);

    while (true)
    {
        chip8.tick();
    }

    return 0;
}