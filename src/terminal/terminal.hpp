#pragma once
#include <string>

struct TerminalSize {
    int width;
    int height;
};

namespace terminal {
TerminalSize detectSize();

void clearScreen();
void moveCursorHome();
void hideCursor();
void showCursor();

void drawText(const std::string &text);
} // namespace terminal
