#include "Game.h"
#include "Utils.h"

const std::string HIGH_SCORE_FILE = "high_score.txt";

Game::Game() : snake(), is_running(true), score(0), high_score(read_high_score(HIGH_SCORE_FILE)), state(MENU) {
    InitAudioDevice();
    eat_sound = LoadSound("C:/Users/Moorthy/Desktop/food.mp3");
    game_over_sound = LoadSound("C:/Users/Moorthy/Desktop/gameover.mp3");
    background_music = LoadMusicStream("C:/Users/Moorthy/Desktop/music.mp3");
    PlayMusicStream(background_music);
    SetMusicVolume(background_music, 0.1f);
    food = new Food(snake.segments);
}

Game::~Game() {
    UnloadSound(eat_sound);
    UnloadSound(game_over_sound);
    UnloadMusicStream(background_music);
    CloseAudioDevice();
    delete food;
}

void Game::render() {
    if (state == MENU) {
        render_menu();
    }
    else if (state == PLAYING) {
        food->render();
        snake.render();
    }
    else if (state == GAME_OVER) {
        render_game_over();
    }
}

void Game::update() {
    UpdateMusicStream(background_music);
    if (state == MENU) {
        update_menu();
    }
    else if (state == PLAYING) {
        snake.update_position();
        check_food_collision();
        check_wall_collision();
        check_self_collision();
    }
    else if (state == GAME_OVER) {
        update_game_over();
    }
}

void Game::check_food_collision() {
    if (Vector2Equals(snake.segments[0], food->position)) {
        delete food;
        food = new Food(snake.segments);
        snake.grow = true;
        score++;
        PlaySound(eat_sound);
    }
}

void Game::check_wall_collision() {
    if (snake.segments[0].x >= grid_size || snake.segments[0].x < 0 || snake.segments[0].y >= grid_size || snake.segments[0].y < 0) {
        game_over();
    }
}

void Game::check_self_collision() {
    for (size_t i = 1; i < snake.segments.size(); i++) {
        if (Vector2Equals(snake.segments[0], snake.segments[i])) {
            game_over();
            break;
        }
    }
}

void Game::game_over() {
    is_running = false;
    PlaySound(game_over_sound);
    if (score > high_score) {
        high_score = score;
        write_high_score(HIGH_SCORE_FILE, high_score);
    }
    state = GAME_OVER;
}

void Game::render_menu() {
    ClearBackground(light_blue);
    DrawText(
        "Snake",
        GetScreenWidth() / 2 - MeasureText("Snake", 40) / 2,
        GetScreenHeight() / 2 - 60,
        40,
        deep_blue
    );
    DrawText(
        "Press ENTER to Start",
        GetScreenWidth() / 2 - MeasureText("Press ENTER to Start", 20) / 2,
        GetScreenHeight() / 2,
        20,
        deep_blue
    );
    DrawText(
        "Press ESC to Exit",
        GetScreenWidth() / 2 - MeasureText("Press ESC to Exit", 20) / 2,
        GetScreenHeight() / 2 + 30,
        20,
        deep_blue
    );
    DrawText(
        TextFormat(
            "High Score: %i", 
            high_score
        ),
        GetScreenWidth() / 2 - MeasureText(
            TextFormat(
                "High Score: %i", 
                high_score
            ), 
            20
        ) / 2,
        GetScreenHeight() / 2 + 60,
        20,
        deep_blue
    );
}

void Game::update_menu() {
    if (IsKeyPressed(KEY_ENTER)) {
        state = PLAYING;
        is_running = true;
        snake.reset();
        delete food;
        food = new Food(snake.segments);
        score = 0;
    }
    else if (IsKeyPressed(KEY_ESCAPE)) {
        CloseWindow();
        exit(0);
    }
}

void Game::render_game_over() {
    ClearBackground(light_blue);
    DrawText(
        "Game Over", 
        GetScreenWidth() / 2 - MeasureText("Game Over", 40) / 2,
        GetScreenHeight() / 2 - 60, 
        40, 
        deep_blue
    );
    DrawText(
        "Press ENTER to Try Again",
        GetScreenWidth() / 2 - MeasureText("Press ENTER to Try Again", 20) / 2,
        GetScreenHeight() / 2, 
        20, 
        deep_blue
    );
    DrawText(
        "Press ESC to Exit", 
        GetScreenWidth() / 2 - MeasureText("Press ESC to Exit", 20) / 2,
        GetScreenHeight() / 2 + 30, 
        20, 
        deep_blue
    );
    DrawText(
        TextFormat(
            "High Score: %i",
            high_score
        ),
        GetScreenWidth() / 2 - MeasureText(
            TextFormat(
            "High Score: %i",
            high_score
            ),
            20
        ) / 2,
        GetScreenHeight() / 2 + 60,
        20,
        deep_blue
    );
}

void Game::update_game_over() {
    if (IsKeyPressed(KEY_ENTER)) {
        state = PLAYING;
        is_running = true;
        snake.reset();
        delete food;
        food = new Food(snake.segments);
        score = 0;
    }
    else if (IsKeyPressed(KEY_ESCAPE)) {
        CloseWindow();
        exit(0);
    }
}