#pragma once

#include <deque>

#include "raylib.h"
#include "raymath.h"

class Food {
public:
    Vector2 position;
    Texture2D sprite;

    Food(const std::deque<Vector2>& snake_body);
    ~Food();
    void render();
    Vector2 find_random_position(const std::deque<Vector2>& snake_body);

private:
    Vector2 random_cell();
};