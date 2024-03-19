#pragma once
#ifndef INSTANCE_H
#define INSTANCE_H

#include <iostream>
#include <vector>
using namespace std;

class Instance {
public:
	int n;
	vector<double> xPos;
	vector<double> yPos;
	vector<vector<double>> cost;
	
	Instance(int numCities);
	void genRandom();
	void distance();
	int getNumCities();
};

#endif