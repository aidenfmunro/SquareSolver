//! @file
//! @author Aiden Munro
//! @version 1.0

#ifndef SOLVINGUTIL_H
#define SOLVINGUTIL_H

/**
 *
 * A enum that sets amount of roots constants.
 *
 */

enum State
{
  INFINITE_ROOTS =  -1,
  NO_ROOTS = 0,
  ONE_ROOT,
  TWO_ROOTS,
  OK
};

/**
 *
 * @param[in] a Coefficient before x^2.
 * @param[in] b Coefficient before x.
 * @param[in] c Coefficient.
 * @param[out] x1 Root of the linear equation.
 *
 * @return Number of roots.
 */

/**
 *
 * \brief Linear equation solver. Puts the root of the equation in x1.
 *
 */

int linearSolver(double b, double c, double *x1);

/**
 * @param[in] a Coefficient before x^2.
 * @param[in] b Coefficient before x.
 * @param[in] c Coefficient.
 * @param[out] x1 Root 1 of the square equation.
 * @param[out] x2 Root 2 of the square equation.
 *
 * @return Number of roots.
 */

/**
 *
 * \brief Square equation solver. Puts the roots of the equation in x1 and x2 if there are 2 roots,
 * if there is 1 root puts it in x1.
 *
 */

int squareSolver(double a, double b, double c, double *x1, double *x2);

/**
 * @param[in] a Coefficient before x^2.
 * @param[in] b Coefficient before x.
 * @param[in] c Coefficient.
 * @param[out] x1 Root 1.
 * @param[out] x2 Root 2.
 *
 * @return Number of roots.
 */

/**
 *
 * \brief Equation solver. This function connects both square and linear functions.
 *
 */

int equationSolver(double a, double b, double c, double *x1, double *x2);

#endif
