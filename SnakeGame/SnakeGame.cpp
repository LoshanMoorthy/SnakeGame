#include <iostream>

#include "Game.h"
#include "Utils.h"

using namespace std;

int main() {
    cout << "Starting the game..." << endl;
    InitWindow(
        2 * screen_margin + cell_dimension * grid_size, 
        2 * screen_margin + cell_dimension * grid_size, 
        "Snake"
    );
    SetTargetFPS(120);

    Game game;
    double update_interval = 0.1;

    while (!WindowShouldClose()) {
        UpdateMusicStream(game.background_music);

        BeginDrawing();
        ClearBackground(light_blue);

        if (should_update(update_interval)) {
            can_move = true;
            game.update();
        }

        if (IsKeyPressed(KEY_UP) && game.snake.movement.y != 1 && can_move) {
            game.snake.movement = { 0, -1 };
            game.is_running = true;
            can_move = false;
        }
        if (IsKeyPressed(KEY_DOWN) && game.snake.movement.y != -1 && can_move) {
            game.snake.movement = { 0, 1 };
            game.is_running = true;
            can_move = false;
        }
        if (IsKeyPressed(KEY_LEFT) && game.snake.movement.x != 1 && can_move) {
            game.snake.movement = { -1, 0 };
            game.is_running = true;
            can_move = false;
        }
        if (IsKeyPressed(KEY_RIGHT) && game.snake.movement.x != -1 && can_move) {
            game.snake.movement = { 1, 0 };
            game.is_running = true;
            can_move = false;
        }

        ClearBackground(light_blue);
        DrawRectangleLinesEx(
            { 
                (float)screen_margin - 5, 
                (float)screen_margin - 5, 
                (float)cell_dimension * grid_size + 10, 
                (float)cell_dimension * grid_size + 10 
            }, 
            5, 
            deep_blue
        );
        DrawText("Snake", screen_margin - 5, 20, 40, deep_blue);
        DrawText(
            TextFormat(
                "%i", 
                game.score
            ), 
            screen_margin - 5, 
            screen_margin + cell_dimension * grid_size + 10, 
            40, 
            deep_blue
        );
        game.render();

        EndDrawing();
    }

    UnloadMusicStream(game.background_music);
    CloseAudioDevice();

    CloseWindow();
    return 0;
}
