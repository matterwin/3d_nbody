#include <nbody_brute.h>
#include <stdio.h>
#include "particle.h"
#include "args.h"
#include "logger.h"

void start_nbody_brute(struct args_t args) 
{
#ifdef DEBUG
    printf("[DEBUG]: Brute force startup\n");
#endif
    Particle* particles;
    int n_particles;
    input_particles(&particles, args, &n_particles);

    print_particles(particles, n_particles);
}


