#ifdef UNIT_TEST
#include <stdio.h>
#include "nu_unit.h"
int nu_tests_run, nu_tests_ok;

static char*
t01()
{
   return NULL;
}

int
main(void)
{
   nu_run_test(t01);

   return !!nu_result();
}
#else
int
main(void)
{
   return 0;
}
#endif
