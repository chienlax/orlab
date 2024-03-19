#include <ilcplex/ilocplex.h>
#include <vector>
#include <iostream>
#include "KData.h"
#include "KVariable.h"

ILOSTLBEGIN

int main(){
    IloEnv env;
    try {
        KnapsackData data;

        IloModel model(env);
        IloCplex cplex(model);

        KnapsackVariables knapsackVars(env, data);

        IloExpr objective(env);
        for (int i = 0; i < knapsackVars.numItems; ++i)
        {
            objective += data.values[i] * knapsackVars.x[i];
        }
        model.add(IloMaximize(env, objective));
        objective.end();

        IloExpr constraint(env);
        for (int i = 0; i < knapsackVars.numItems; ++i) {
            constraint += data.weights[i] * knapsackVars.x[i];
        }
        model.add(constraint <= data.capacity);
        constraint.end();

        cplex.solve();


        std::cout << "Objective Value: " << cplex.getObjValue() << std::endl;
        for (int i = 0; i < knapsackVars.numItems; ++i) {
            std::cout << "Item " << i << ": " << cplex.getValue(knapsackVars.x[i]) << std::endl;
        }
    }
    catch (IloException& ex) 
    {
        cerr << "Error: " << ex << endl;
        ex.end();
    }
    env.end();
    return 0;
}

