//! @file
//! @author Aiden Munro
//! @version 1.0

#ifndef MINORUTIL_H
#define MINORUTIL_H

/**
 *
 * A enum that
 *
 */

enum yes_or_no_char
{
  YES = 1,
  NO  = 0
};

/**
 *
 * @param a Coefficient before x^2.
 * @param b Coefficient before x.
 * @param c Coefficient.
 *
 * \brief This function inputs the coefficients.
 *
 * @return Whether the program went ok.
 */

int input(double *a, double *b, double *c);

/**
 *
 * @param numRoots Number of roots.
 * @param x1 Root 1.
 * @param x2 Root 2.
 *
 * @return Whether the program went ok.
 *
 */

/**
 *
 * \brief Function that prints the amount of roots and the roots.
 *
 */

int output(int numRoots, double *x1, double *x2);

/**
 *
 * \brief This function ignores spaces after a user has written the coefficients.
 *
 */

int checkInput(void);

#endif
