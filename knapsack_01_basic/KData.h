#ifndef KNAPSACK_DATA_H
#define KNAPSACK_DATA_H

#include <vector>

class KnapsackData {
public:
    std::vector<int> values;
    std::vector<int> weights;
    int capacity;

    KnapsackData() {
        // Initialize your data here
        values = { 10, 4, 7, 5, 3 };
        weights = { 2, 3, 4, 7, 8 };
        capacity = 10;
    }
};

#endif // KNAPSACK_DATA_H
