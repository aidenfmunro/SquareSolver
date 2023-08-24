#ifndef MYASSERT_H
#define MYASSERT_H

#define myAssert(EXPRESSION, ERROR_CODE)                              \
    if (! (EXPRESSION))                                               \
      {                                                               \
        fprintf (stderr, printError(ERROR_CODE), __FILE__, __LINE__); \
        exit(1);                                                      \
      }

const char* printError(int state);

enum ERRORS
{
    IS_FINITE_ERROR = 1,
    NULL_ERROR = 2
};



#endif
