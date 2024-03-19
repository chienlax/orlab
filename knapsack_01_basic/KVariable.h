#ifndef KNAPSACK_VARIABLES_H
#define KNAPSACK_VARIABLES_H

#include <ilcplex/ilocplex.h>
#include <vector>
#include "KData.h" // Include the header file with data declarations

ILOSTLBEGIN

class KnapsackVariables {
public:
    IloNumVarArray x;
    int numItems;

    KnapsackVariables(IloEnv env, const KnapsackData& data) : numItems(data.values.size()) {
        x = IloNumVarArray(env, numItems, 0, 1, ILOBOOL);
    }
};

#endif // KNAPSACK_VARIABLES_H
