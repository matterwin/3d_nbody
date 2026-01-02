#include <stdio.h>
#include <pthread.h>

#include "nbody.h"
#include "args.h"
#include "graphics.h"

int main(int argc, char** argv)
{
    struct args_t args;
    get_args(&args, argc, argv);

    pthread_t sim_t;
    pthread_create(&sim_t, NULL, nbody_t_start, &args);

    graphics_loop(argc, argv, &args);

    pthread_join(sim_t, NULL);

    return 0;
}
