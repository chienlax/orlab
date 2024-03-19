#include "instance.h"
#include <random>
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

Instance::Instance(int numCities) : 
	n(numCities), xPos(numCities), yPos(numCities), 
	cost(numCities, vector<double>(numCities)) {}

void Instance::genRandom() {
	random_device rd;
	mt19937 gen(rd());

	int min_value = 0;
	int max_value = 100;

	uniform_real_distribution<> distrib(min_value, max_value);

	for (int i = 0; i < n; i++) {
		int random_value = distrib(gen);
		xPos[i] = random_value;
	}

	for (int i = 0; i < n; i++) {
		int random_value = distrib(gen);
		yPos[i] = random_value;
	}
}

void Instance::distance() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cost[i][j] = sqrt(pow(xPos[i] - xPos[j], 2) + pow(yPos[i] - yPos[j], 2));
		}
	}
}

int Instance::getNumCities(){
	return n;
}