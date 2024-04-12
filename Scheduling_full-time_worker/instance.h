#pragma once
#ifndef INSTANCE_H
#define INSTANCE_H

#include <iostream>
#include <vector>

using namespace std;

class Instance {
public:
	int n; // no of shift
	int T; // no of time window
	vector<int> required_worker; // no of workers required
	vector<int> wage; // wage rate per shift
	vector<vector<int>> covered; //shift j cover time window T or not

	Instance(string instanceFile);
	void read_input(const string& inputFile);
};

#endif

