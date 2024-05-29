#pragma once

#include "Snake.h"
#include "Utils.h"
#include "Food.h"
#include "raylib.h"

class Game {
public:
    Snake snake;
    Food* food;
    bool is_running;
    int score;
    int high_score;
    Sound eat_sound;
    Sound game_over_sound;
    Music background_music;
    GameState state;

    Game();
    ~Game();
    void render();
    void update();
    void check_food_collision();
    void check_wall_collision();
    void check_self_collision();
    void game_over();
    void render_menu();
    void render_game_over();
    void update_menu();
    void update_game_over();
};
