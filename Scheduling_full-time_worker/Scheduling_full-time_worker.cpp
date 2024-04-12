#include "solver.h"
#include "instance.h"


int main()
{
    Instance instance("input.txt");
    Solver solver(&instance);
    solver.run();
}
