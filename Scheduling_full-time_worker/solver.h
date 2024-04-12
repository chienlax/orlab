#pragma once

#ifndef SOLVER_H
#define SOLVER_H

#include <iostream>
#include "instance.h"
#include <ilcplex/ilocplex.h>

ILOSTLBEGIN
typedef IloArray<IloNumVarArray> NumVar2D;

using namespace std;

class Solver {
public:
    Solver(Instance*);

    Instance* instance;

	int n; 
	int T; 
	vector<int> required_worker; 
	vector<int> wage;
	vector<vector<int>> covered;

    void run();
};

#endif
