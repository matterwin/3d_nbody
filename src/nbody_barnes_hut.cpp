#include <nbody_brute.h>
#include <stdio.h>

void start_nbody_barnes_hut(struct args_t args)
{
#ifdef DEBUG
    printf("[DEBUG]: start_nbody_barnes_hut...\n");
#endif
    Particle* particles;
    int n_particles;
    input_particles(&particles, args, &n_particles);
}


