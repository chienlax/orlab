#include "instance.h"
#include "solver.h"

using namespace std;

int main()
{
    Instance instance(10);

    Solver solver(&instance);
    solver.run();

    return 0;
}
