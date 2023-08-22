#include <TXLib.h>
#include "solvingutil.h"
#include "ioutil.h"

int main()
{
    double a = NAN, b = NAN, c = NAN, x1 = NAN, x2 = NAN;

    input(&a, &b, &c);

    int result = equationSolver(a, b, c, &x1, &x2);

    output(result, &x1, &x2);
}
