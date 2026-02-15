#include "world.hpp"

World::World(int width, int height)
    : width(width), height(height),
      current(static_cast<size_t>(width * height), 0),
      next(static_cast<size_t>(width * height), 0) {}

static int wrapTerminal(int value, int modulo) {
    value %= modulo;
    if (value < 0)
        value += modulo;
    return value;
}

static int positionOfCell(int x, int y, int width) { return y * width + x; }

uint8_t World::isAlive(int x, int y) const {
    x = wrapTerminal(x, width);
    y = wrapTerminal(y, height);
    return current[positionOfCell(x, y, width)];
}

void World::setAlive(int x, int y) {
    x = wrapTerminal(x, width);
    y = wrapTerminal(y, height);
    current[positionOfCell(x, y, width)] = 1;
}

static int countAliveNeighbors(const World &world, int x, int y) {
    static constexpr int neighborsOffsets[8][2] = {
        {-1, -1}, {0, -1}, {1, -1}, {-1, 0}, {1, 0}, {-1, 1}, {0, 1}, {1, 1}};

    int count = 0;

    for (const auto &offsetPair : neighborsOffsets) {
        count += world.isAlive(x + offsetPair[0], y + offsetPair[1]);
    }

    return count;
}

void World::step() {
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            const int position = positionOfCell(x, y, width);
            const int neighbors = countAliveNeighbors(*this, x, y);
            const uint8_t alive = current[position];

            next[position] =
                (neighbors == 3 || (alive && neighbors == 2)) ? 1 : 0;
        }
    }

    current.swap(next);
}
