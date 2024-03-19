#include "solver.h"
#include <iostream>

using namespace std;

Solver::Solver(Instance* instance) : instance(instance) {
    

    instance->genRandom();
    instance->distance();

    n = instance->n;
    xPos = instance->xPos;
    yPos = instance->yPos;
    cost = instance->cost;
    
}

void Solver::run() {
    IloEnv env;
    try {

        IloModel model(env);

        IloArray<IloNumVarArray> X(env, n);
        for (int i = 0; i < n; ++i) {
            X[i] = IloNumVarArray(env, n);
            for (int j = 0; j < n; j++) {
                X[i][j] = IloNumVar(env, 0, 1, ILOINT);
            }
        }

        IloExpr objective(env);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                objective += cost[i][j] * X[i][j];
            }
        }
        model.add(IloMinimize(env, objective));

        // Constraints
        for (int i = 0; i < n; ++i) {
            IloExpr sum(env);
            for (int j = 0; j < n; ++j) {
                if (i != j) {
                    sum += X[i][j];
                }
            }
            model.add(sum == 1);
        }

        for (int j = 0; j < n; ++j) {
            IloExpr sum(env);
            for (int i = 0; i < n; ++i) {
                if (i != j) {
                    sum += X[i][j];
                }
            }
            model.add(sum == 1);
        }

        IloNumVarArray u(env, n, 0, IloInfinity);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    model.add(u[i] - u[j] + (n - 1) * X[i][j] <= n - 1);
                }
            }
        }

        // Solve the model
        IloCplex cplex(model);
        cplex.setOut(env.getNullStream());
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