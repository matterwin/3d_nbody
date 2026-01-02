#include "logger.h"
#include <stdio.h>

void print_particle(Particle p)
{
    printf("%d %.6f %.6f %.6f %d %.6f %.6f %.6f\n",
        p.idx,
        p.px, p.py, p.pz,
        p.mass,
        p.vx, p.vy, p.vz);
}

void print_particles(Particle* particles, int n_particles)
{
    printf("%d\n", n_particles);
    for (int i = 0; i < n_particles; ++i)
        print_particle(particles[i]);
}
