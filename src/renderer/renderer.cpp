#include "renderer.hpp"

#include <string>

std::string renderer::renderWorld(const World &world) {
    std::string frame;
    frame.reserve(
        static_cast<size_t>(world.width * world.height + world.height));

    for (int i = 0; i < world.width * world.height; i++) {
        frame += world.current[i] ? "█" : " ";

        if ((i + 1) % world.width == 0) {
            frame += '\n';
        }
    }

    return frame;
}
