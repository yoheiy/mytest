int
test(char **argv)
{
   return 0;
}

#ifdef UNIT_TEST
#include <stdio.h>
#include "nu_unit.h"
int nu_tests_run, nu_tests_ok;

static char*
t01()
{
   char *argv[] = { "test", NULL };

   nu_assert(test(argv) == 1);
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
main(int argc, char **argv)
{
   return test(argv);
}
#endif
