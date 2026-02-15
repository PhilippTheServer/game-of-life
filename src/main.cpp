#include "terminal/terminal.hpp"
#include "world/world.hpp"
#include <chrono>
#include <iostream>
#include <thread>

// game logic
// Rules:
// 1. A Cell that has less then 2 neighboors dies.
// 2. A Cell that has 2 - 3 alive neighboors lives.
// 3. A Cell that has more then 3 alive neighboors dies.
// 4. A Cell that hsa 3 alive neighboors gets alive too.

// Seat a random layout on start

// logic to precompute next alive cells to avoid fps drops

void prepare_terminal() {
    terminal::clearScreen();
    terminal::moveCursorHome();
    terminal::hideCursor();
}

int simulation(TerminalSize size) {
    World world(size.width, size.height);

    world.setAlive(1, 0);
    world.setAlive(2, 1);
    world.setAlive(0, 2);
    world.setAlive(1, 2);
    world.setAlive(2, 2);

    while (true) {
        world.step();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    return 0;
}

int main() {
    std::cout << "\nGAME OF Life\n";

    TerminalSize size = terminal::detectSize();
    prepare_terminal();
    simulation(size);
    terminal::showCursor();
    // Debug: print terminal size
    // std::cout << "Width: " << size.width << "\n";
    // std::cout << "Height: " << size.height << "\n";

    return 0;
}
