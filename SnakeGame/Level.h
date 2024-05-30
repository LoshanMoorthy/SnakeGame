#pragma once

#include <vector>

#include "raylib.h"
#include "raymath.h"

class Level {
public:
	int level_number;
	std::vector<Rectangle> obstacles;

	Level(int number);
	void load_level();
	void render();
	bool check_collision_with_obstacles(Vector2 position);
};