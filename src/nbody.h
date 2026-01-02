#include "nbody_brute.h"
#include "nbody_barnes_hut.h"
#include "args.h"

void* nbody_t_start(void* arg)
{
#ifdef DEBUG
    printf("[DEBUG]: nbody_t_start...\n");
    fflush(stdout);
#endif

    struct args_t* args = (struct args_t*) arg; 
    if (args->brute)
        start_nbody_brute(*args);
    else 
        start_nbody_barnes_hut(*args);

    return NULL;
}
