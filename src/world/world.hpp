#pragma once
#include <cstdint>
#include <random>
#include <vector>

struct World {
    int width;
    int height;

    std::vector<uint8_t> current;
    std::vector<uint8_t> next;

    World(int width, int height);

    void step();

    void setAlive(int x, int y);
    uint8_t isAlive(int x, int y) const;

    void randomize(double density = 0.25);
};
