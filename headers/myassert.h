//! @file
//! @author Aiden Munro
//! @version 1.0

#ifndef MYASSERT_H
#define MYASSERT_H

enum ERRORS
{
    IS_FINITE_ERROR = 1,
    NULL_ERROR = 2
};
static const char *ERROR_MSG[] = {"Number is not finite", "Number is null"};

static const int SHIFT = 1;
/**
 *
 * Assert macro.
 *
 */

#define myAssert(EXPRESSION, ERROR_CODE)                                       \
                            if (! (EXPRESSION))                                \
                              {                                                \
        fprintf (stderr,"%s, failed at %s:%d\n", ERROR_MSG[ERROR_CODE - SHIFT] \
        , __FILE__, __LINE__);                                                 \
        exit(ERROR_CODE);                                                                              \
      }
/**
 *
 * @param Expression.
 *
 * @return String with the error code.
 *
 */

const char* printError(int state);

/**
 *
 * A enum that sets error codes.
 *
 */

#endif
