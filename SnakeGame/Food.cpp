#include <stdexcept>

#include "Food.h"
#include "Utils.h"

Food::Food(const std::deque<Vector2>& snake_body) {
    Image image = LoadImage("C:/Users/Moorthy/Desktop/Food.png");
    if (!image.data) {
        throw std::runtime_error("Failed to load image: Food.png");
    }
    sprite = LoadTextureFromImage(image);
    UnloadImage(image);
    position = find_random_position(snake_body);
}

Food::~Food() {
    UnloadTexture(sprite);
}

void Food::render() {
    DrawCircle(
        screen_margin + position.x * cell_dimension + cell_dimension / 2,
        screen_margin + position.y * cell_dimension + cell_dimension / 2,
        cell_dimension / 2,
        RED
    );
    DrawRectangle(
        screen_margin + position.x * cell_dimension + cell_dimension / 2 - 2,
        screen_margin + position.y * cell_dimension + cell_dimension / 2 - cell_dimension / 2 - 4,
        4,
        8,
        BROWN
    );
    DrawTriangle(
        Vector2
        { 
            screen_margin + position.x * cell_dimension + cell_dimension / 2 + 4,
            screen_margin + position.y * cell_dimension + cell_dimension / 2 - cell_dimension / 2 - 2 
        },
        Vector2
        { 
            screen_margin + position.x * cell_dimension + cell_dimension / 2 + 8,
            screen_margin + position.y * cell_dimension + cell_dimension / 2 - cell_dimension / 2 - 10 
        },
        Vector2
        { 
            screen_margin + position.x * cell_dimension + cell_dimension / 2 + 12,
            screen_margin + position.y * cell_dimension + cell_dimension / 2 - cell_dimension / 2 - 2 
        },
        GREEN
    );
}


Vector2 Food::random_cell() {
    float x = GetRandomValue(0, grid_size - 1);
    float y = GetRandomValue(0, grid_size - 1);
    return Vector2{ x, y };
}

Vector2 Food::find_random_position(const std::deque<Vector2>& snake_body) {
    Vector2 pos = random_cell();
    while (element_in_deque(pos, snake_body)) {
        pos = random_cell();
    }
    return pos;
}
