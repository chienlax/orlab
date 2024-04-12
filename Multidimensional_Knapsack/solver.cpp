#include "solver.h"
#include <iostream>

using namespace std;

Solver::Solver(Instance* instance) : instance(instance) {
    n = instance->n;
    m = instance->m;
    ans = instance->ans;
    capacity = instance->capacity;
    profit = instance->profit;
    resource_need = instance->resource_need;
}

void Solver::run() {
    IloEnv env;
    try {
        //cout << n;

        IloModel model(env);

        IloNumVarArray X(env, n);
        for (int i = 0; i < n; ++i) {
            X[i] = IloNumVar(env, 0, 1, ILOINT);
        }

        //objective function
        IloExpr objective(env);
        for (int i = 0; i < n; ++i) {
            objective += profit[i] * X[i];       
        }
        model.add(IloMaximize(env, objective));

        // Constraints
        for (int i = 0; i < m; ++i) {
            IloExpr expr1(env);
            for (int j = 0; j < n; ++j) {
                expr1 += X[j] * resource_need[i][j];
            }
            model.add(expr1 <= capacity[i]);
        }

        // Solve the model
        IloCplex cplex(model);
        //cplex.setOut(env.getNullStream());
        if (!cplex.solve()) {
            cerr << "Failed to solve the problem" << endl;
            throw(-1);
        }

        double objValue = cplex.getObjValue();

        env.end();

        cout << objValue;
    }
    catch (IloException& e) {
        cerr << "Concert exception caught: " << e << endl;
        throw(-1);
    }
}