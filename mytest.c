int
test(char **argv)
{
   /* option -z */
   if (argv[1] && argv[1][0] == '-' && argv[1][1] == 'z' && !argv[1][2])
      return argv[1] && *argv[1] && !argv[2]? 1 : 0;

   /* skip -n */
   if (argv[1] && argv[1][0] == '-' && argv[1][1] == 'n' && !argv[1][2])
      argv++;

   return argv[1] && *argv[1] && !argv[2]? 0 : 1;
}

#ifdef UNIT_TEST
#include <stdio.h>
#include "nu_unit.h"
int nu_tests_run, nu_tests_ok;

/* if nothing given as arg, it fail */
static char*
t01()
{
   char *argv[] = { "test", NULL };

   nu_assert(test(argv) == 1);
   return NULL;
}

/* if one string is given, it succeed */
static char*
t02()
{
   char *argv[] = { "test", "test", NULL };

   nu_assert(test(argv) == 0);
   return NULL;
}

/* if one empty string is given, it fail */
static char*
t03()
{
   char *argv[] = { "test", "", NULL };

   nu_assert(test(argv) == 1);
   return NULL;
}

/* if two string is given, it fail */
static char*
t04()
{
   char *argv[] = { "test", "spam", "eggs", NULL };

   nu_assert(test(argv) == 1);
   return NULL;
}

/* if -n and non-empty string is given, it succeed */
static char*
t05()
{
   char *argv[] = { "test", "-n", "spam", NULL };

   nu_assert(test(argv) == 0);
   return NULL;
}

/* if -z and empty string is given, it succeed */
static char*
t06()
{
   char *argv[] = { "test", "-z", "", NULL };

   nu_assert(test(argv) == 0);
   return NULL;
}

int
main(void)
{
   nu_run_test(t01);
   nu_run_test(t02);
   nu_run_test(t03);
   nu_run_test(t04);
   nu_run_test(t05);
   nu_run_test(t06);

   return !!nu_result();
}
#else
int
main(int argc, char **argv)
{
   return test(argv);
}
#endif
