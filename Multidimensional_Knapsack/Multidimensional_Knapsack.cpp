#include <iostream>
#include "solver.h"
#include "instance.h"

int main()
{
    Instance instance("multidimensional_kp.txt");
    Solver solver(&instance);
    solver.run();
}
