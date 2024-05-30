#include "Snake.h"
#include "Utils.h"

Snake::Snake() : segments({ {6, 9}, {5, 9}, {4, 9} }), movement({ 1, 0 }), grow(false) {}

void Snake::render() {
    for (const auto& segment : segments) {
        float x = segment.x;
        float y = segment.y;
        Rectangle rect =
        {
            screen_margin + x * cell_dimension, screen_margin + y * cell_dimension,
            (float)cell_dimension, (float)cell_dimension
        };
        DrawRectangleRounded(rect, 0.5, 6, deep_blue);
    }
}

void Snake::update_position() {
    segments.push_front(Vector2Add(segments[0], movement));
    if (!grow) {
        segments.pop_back();
    }
    grow = false;
}

void Snake::reset() {
    segments = { {6, 9}, {5, 9}, {4, 9} };
    movement = { 1, 0 };
}