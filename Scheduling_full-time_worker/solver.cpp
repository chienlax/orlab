#include "solver.h"
#include <iostream>

using namespace std;

Solver::Solver(Instance* instance) : instance(instance) {
    n = instance->n;
    T = instance->T;
    required_worker = instance->required_worker;
    wage = instance->wage;
    covered = instance->covered;
}
void Solver::run() {
    IloEnv env;
    try {
        IloModel model(env);

        IloNumVarArray X(env, n);
        for (int i = 0; i < n; ++i) {
            X[i] = IloNumVar(env, 0, IloInfinity, ILOFLOAT);
        }

        // Objective function
        IloExpr objective(env);
        for (int i = 0; i < n; ++i) {
            objective += wage[i] * X[i];
        }
        model.add(IloMinimize(env, objective));

        // Constraints
        for (int i = 0; i < T; ++i) {
            IloExpr expr1(env);
            for (int j = 0; j < n; ++j) {
                expr1 += X[j] * covered[i][j];
            }
            model.add(expr1 >= required_worker[i]);
        }

        // Solve the model
        IloCplex cplex(model);
        if (!cplex.solve()) {
            cerr << "Failed to solve the problem" << endl;
            throw(-1);
        }

        double objValue = cplex.getObjValue();

        //env.end();

        cout << objValue << endl;

        for (int i = 0; i < n; ++i) {
            cout << "X[" << i << "] = " << cplex.getValue(X[i]) << endl;
        }

        env.end();
    }
    catch (IloException& e) {
        cerr << "Concert exception caught: " << e << endl;
        throw(-1);
    }
}