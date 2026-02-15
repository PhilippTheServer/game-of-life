#include <iostream>
#include <stdexcept>
#include <sys/ioctl.h>
#include <unistd.h>

// game logic
// Rules:
// 1. A Cell that has less then 2 neighboors dies.
// 2. A Cell that has 2 - 3 alive neighboors lives.
// 3. A Cell that has more then 3 alive neighboors dies.
// 4. A Cell that hsa 3 alive neighboors gets alive too.

// Terminal as canvas:
// 1. Get current width and height to use as the borders
// 2. Reduce flickering
// 3. Remove cursor
// 4. Draw on the Terminal
struct TerminalSize {
    int width;
    int height;

    static TerminalSize detect_size() {
        struct winsize windowInfo{};

        if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &windowInfo) == -1) {
            throw std::runtime_error("\nUnable to detect terminal size.\n");
        }

        return TerminalSize{static_cast<int>(windowInfo.ws_col),
                            static_cast<int>(windowInfo.ws_row)};
    }
};

// Seat a random layout on start

// logic to precompute next alive cells to avoid fps drops

int main() {
    std::cout << "\nGAME OF Life\n";

    // Debug: print terminal size
    TerminalSize terminal = TerminalSize::detect_size();

    std::cout << "Width: " << terminal.width << "\n";
    std::cout << "Height: " << terminal.height << "\n";
    return 0;
}
