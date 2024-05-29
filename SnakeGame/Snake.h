#pragma once

#include <deque>

#include "raylib.h"
#include "raymath.h"

class Snake {
public:
public:
    std::deque<Vector2> segments;
    Vector2 movement;
    bool grow;

    Snake();
    void render();
    void update_position();
    void reset();
};