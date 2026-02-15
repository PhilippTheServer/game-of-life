#pragma once

struct TerminalSize {
    int width;
    int height;
};

namespace terminal {
TerminalSize detectSize();

void clearSreen();
void moveCursorHome();
void hideCursor();
void showCursor();
} // namespace terminal
