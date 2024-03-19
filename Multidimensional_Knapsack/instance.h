#pragma once
#ifndef INSTANCE_H
#define INSTANCE_H

#include <iostream>
#include <vector>

using namespace std;

class Instance {
public:
	int n, m, ans; // n variables, m constraint, answer
	vector<int> capacity; // 1xm matrix
	vector<int> profit; // nx1 matrix
	vector<vector<int>> resource_need; // m x n matrix

	Instance(string instanceFile);
	void read_input(const string& inputFile);
};

#endif

