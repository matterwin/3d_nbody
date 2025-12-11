#pragma once

typedef struct args_t 
{
    double theta;       // threshold for approximation
    double dt;          // step-size of simulation
    char *in_file;   
    char *out_file;   
    bool brute;
} args;

void get_args(struct args_t* args, int argc, char** argv);

