#include "Level.h"
#include "Utils.h"

Level::Level(int number) : level_number(number) {
    load_level();
}

void Level::load_level() {
    obstacles.clear();
    if (level_number == 1) {
        // no obstacles..
    }
    else if (level_number == 2) {
        obstacles.push_back(Rectangle{ (float)screen_margin + 5 * cell_dimension, (float)screen_margin + 5 * cell_dimension, (float)cell_dimension, (float)cell_dimension });
        obstacles.push_back(Rectangle{ (float)screen_margin + 10 * cell_dimension, (float)screen_margin + 10 * cell_dimension, (float)cell_dimension, (float)cell_dimension });
    }
    else if (level_number == 3) {
        obstacles.push_back(Rectangle{ (float)screen_margin + 3 * cell_dimension, (float)screen_margin + 3 * cell_dimension, (float)cell_dimension, (float)7 * cell_dimension });
        obstacles.push_back(Rectangle{ (float)screen_margin + 15 * cell_dimension, (float)screen_margin + 15 * cell_dimension, (float)3 * cell_dimension, (float)cell_dimension });
    }
}

void Level::render() {
    for (const auto& obstacle : obstacles) {
        DrawRectangleRec(obstacle, DARKGRAY);
    }
}

bool Level::check_collision_with_obstacles(Vector2 position) {
    Vector2 screen_position = { screen_margin + position.x * cell_dimension, screen_margin + position.y * cell_dimension };
    for (const auto& obstacle : obstacles) {
        if (CheckCollisionPointRec(screen_position, obstacle)) {
            return true;
        }
    }
    return false;
}
