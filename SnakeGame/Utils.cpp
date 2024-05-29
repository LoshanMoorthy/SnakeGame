#include <fstream>
#include <iostream>

#include "Utils.h"

Color light_blue = {0, 122, 255, 255};
Color deep_blue = {0, 51, 102, 255};

int cell_dimension = 30;
int grid_size = 25;
int screen_margin = 75;
double last_frame_time = 0;
bool can_move = false;
double debounce_time = 0.2;

bool element_in_deque(Vector2 element, std::deque<Vector2> deque) {
	for (unsigned int i = 0; i < deque.size(); i++) {
		if (Vector2Equals(deque[i], element)) {
			return true;
		}
	}
	return false;
}

bool should_update(double interval) {
	double current_time = GetTime();
	if (current_time - last_frame_time >= interval) {
		last_frame_time = current_time;
		return true;
	}
	return false;
}

int read_high_score(const std::string& filename) {
	std::ifstream file(filename);
	int high_score = 0;
	if (file.is_open()) {
		file >> high_score;
		file.close();
	}
	else {
		std::ofstream new_file(filename);
		if (new_file.is_open()) {
			new_file << high_score;
			new_file.close();
		}
	}
	return high_score;
}

void write_high_score(const std::string& filename, int high_score) {
	std::ofstream file(filename);
	if (file.is_open()) {
		file << high_score;
		file.close();
	}
}
