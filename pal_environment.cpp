#include <stdlib.h>
#include <string.h>

extern "C" char** CoreLibNative_EnvironGetSystemEnvironment()
{
    char** sysEnviron;

#if HAVE__NSGETENVIRON
    sysEnviron = *(_NSGetEnviron());
#else   // HAVE__NSGETENVIRON
    extern char **environ;
    sysEnviron = environ;
#endif  // HAVE__NSGETENVIRON

    return sysEnviron;
}