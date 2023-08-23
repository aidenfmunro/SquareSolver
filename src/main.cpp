#include <TXLib.h>
#include <string.h>
#include "../headers/solvingutil.h"
#include "../headers/ioutil.h"
#include "../headers/tester.h"

int main(int n, char *argv[])
{
    if (strcmp (argv[1], "t-") != 0)
      {
        double a = NAN, b = NAN, c = NAN, x1 = NAN, x2 = NAN;

        input(&a, &b, &c);

        int numRoots = equationSolver(a, b, c, &x1, &x2);

        output(numRoots, &x1, &x2);
      }
    else if (strcmp (argv[1], "solve") != 0)
      {
        testEquation();
      }
}
