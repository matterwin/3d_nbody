#ifndef PARTICLE_H
#define PARTICLE_H

typedef struct Particle 
{
    double px, py, pz;  // position
    double vx, vy, vz;  // velocity
    double fx, fy, fz;  // gravity force

    int mass;
    int idx;
} Particle;

#endif
