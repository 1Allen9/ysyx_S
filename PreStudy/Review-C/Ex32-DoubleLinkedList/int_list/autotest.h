#ifndef __AUTOTEST_H__
#define __AUTOTEST_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define test_is_eq(A, B, msg)  {(A == B) ?  printf(" %s eq test pass\n", msg) : printf(" %s err\n", msg);}

#endif

