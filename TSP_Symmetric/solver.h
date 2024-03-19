#ifndef SOLVER_H
#define SOLVER_H

#include "instance.h"
#include <ilcplex/ilocplex.h>
#include <iostream>
#include <vector>
ILOSTLBEGIN

using namespace std;

class Solver {
public:

	Solver(Instance*);

	Instance* instance;
	int n;
	vector<double> xPos;
	vector<double> yPos;
	vector<vector<double>> cost;

	void run();
};

#endif