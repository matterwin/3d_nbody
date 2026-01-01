#include <nbody_brute.h>
#include <stdio.h>
#include "particle.h"
#include "args.h"

void start_nbody_brute(struct args_t args) 
{
#ifdef DEBUG
    printf("[DEBUG]: Brute force startup\n");
#endif
    Particle* particles;
    input_particles(&particles, args);


}


