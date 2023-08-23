#ifndef SOLVINGUTIL_H
#define SOLVINGUTIL_H

enum State
{
  INFINITE_ROOTS =  -1,
  NO_ROOTS = 0,
  ONE_ROOT,
  TWO_ROOTS,
  OK
};

int linearSolver(double b, double c, double *x1);

int squareSolver(double a, double b, double c, double *x1, double *x2);

int equationSolver(double a, double b, double c, double *x1, double *x2);

#endif
