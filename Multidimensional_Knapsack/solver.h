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

    int n, m, ans;
    vector<int> capacity;
    vector<int> profit;
    vector<vector<int>> resource_need;

    void run();
};

#endif
