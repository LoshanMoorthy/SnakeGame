#pragma once

#include <deque>
#include <string>

#include "raylib.h"
#include "raymath.h"

extern Color light_blue;
extern Color deep_blue;
extern int cell_dimension;
extern int grid_size;
extern int screen_margin;
extern double last_frame_time;
extern bool can_move;
extern double debounce_time;

enum GameState {
    MENU,
    PLAYING,
    GAME_OVER
};

bool element_in_deque(Vector2 element, std::deque<Vector2> deque);
bool should_update(double interval);
int read_high_score(const std::string& filename);
void write_high_score(const std::string& filename, int high_score);


