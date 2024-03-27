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

	int num_nodes; //done
	int num_drones; //done
	int speed_drone; //done
	int speed_truck; //done

	vector<vector<int>> nodes; //done
	set<int> drone_only; //done
	vector<vector<int>> distance_man; // round to nearest integer - done
	vector<vector<int>> distance_eucl; // round to nearest integer - done
	vector<vector<int>> time_truck; // round to nearest integer - done
	vector<vector<int>> time_drone; // round to nearest integer - done

    void run();
};

#endif
