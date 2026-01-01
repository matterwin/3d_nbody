#pragma once

#include "particle.h"

typedef struct args_t 
{
    double theta;       // threshold for approximation
    double dt;          // step-size of simulation
    char *input_file;   
    char *output_file;   
    bool brute;
    bool verbose;
    bool help;
} args;

void get_args(struct args_t* args, int argc, char** argv);
void input_particles(Particle** particles, struct args_t args);


