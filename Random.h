#pragma once
#include <random>

class Random {
	std::random_device rd;
	std::mt19937 gen;
public:
	Random() {
		gen.seed(rd());
	}
	float getRandomInt(int l, int u) {
		std::uniform_int_distribution<int> dist(l, u);
		return dist(gen);
	}
};
