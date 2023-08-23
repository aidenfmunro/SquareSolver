#include <TXLib.h>
#include "../headers/solvingutil.h"
#include "../headers/ioutil.h"
#include "../headers/tester.h"

int main()
{
    double a = NAN, b = NAN, c = NAN, x1 = NAN, x2 = NAN;

    input(&a, &b, &c);

    int numRoots = equationSolver(a, b, c, &x1, &x2);

    output(numRoots, &x1, &x2);

    // testEquation();
}
