#define nu_assert(exp) do { if (!(exp)) return #exp; } while (0)
#define nu_run_test(test) do { \
   const char *mesg = test(); nu_tests_run++; \
   if (mesg) printf("[failed] " #test " : %s\n", mesg); \
   else nu_tests_ok++; \
 } while (0)
#define nu_result() (nu_tests_run - nu_tests_ok)
extern int nu_tests_run, nu_tests_ok;
