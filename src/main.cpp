#include <stdio.h>
#include "nbody_brute.h"
#include "nbody_barnes_hut.h"
#include "args.h"
#include <pthread.h>
#include <cuda_runtime.h>

int main(int argc, char** argv)
{
    struct args_t args;
    get_args(&args, argc, argv);

    printf("test\n");

    // spawn a thread here
    
    pthread_create(

    if (args.brute)
        start_nbody_brute(args);
    else 
        start_nbody_barnes_hut(args);
    
    return 0;
}
