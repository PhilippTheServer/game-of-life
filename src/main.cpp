#include "terminal/terminal.hpp"
#include <iostream>

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

int main() {
    std::cout << "\nGAME OF Life\n";

    TerminalSize size = terminal::detectSize();
    prepare_terminal();

    terminal::showCursor();
    // Debug: print terminal size
    std::cout << "Width: " << size.width << "\n";
    std::cout << "Height: " << size.height << "\n";

    return 0;
}
