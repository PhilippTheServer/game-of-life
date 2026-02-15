#include "terminal.hpp"
#include <iostream>
#include <stdexcept>
#include <sys/ioctl.h>
#include <unistd.h>

TerminalSize terminal::detectSize() {
    struct winsize windowInfo{};

    if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &windowInfo) == -1) {
        throw std::runtime_error("\nUnable to detect terminal size.\n");
    }

    return TerminalSize{static_cast<int>(windowInfo.ws_col),
                        static_cast<int>(windowInfo.ws_row)};
}

void terminal::clearScreen() { std::cout << "\x1b[2J"; }

void terminal::moveCursorHome() { std::cout << "\x1b[H"; }

void terminal::hideCursor() { std::cout << "\x1b[?25l"; }

void terminal::showCursor() { std::cout << "\x1b[?25h"; }

void terminal::drawText(const std::string &text) {
    std::cout << text;
    std::cout.flush();
}
