#include "args.h"
#include <getopt.h>
#include <stdio.h>
#include <cstdlib>

#include "particle.h"

#define REG_ARG_COUNT 4

void get_args(struct args_t* args, int argc, char** argv)
{
    args->theta = 0.0;
    args->dt = 0.0;
    args->input_file = NULL;
    args->output_file = NULL;
    args->brute = false;
    args->verbose = false;
    args->help = false;

    struct option l_opts[] = {
        {"input",   required_argument, 0, 'i'},
        {"output",  required_argument, 0, 'o'},
        {"dt",      required_argument, 0, 'd'},
        {"theta",   required_argument, 0, 't'},
        {"verbose", optional_argument, 0, 'v'},
        {"help",    optional_argument, 0, 'h'},
        {"brute",   optional_argument, 0, 'b'},
        {0, 0, 0, 0}
    };

    int req_args[REG_ARG_COUNT] = {0};

    int opt;
    while ((opt = getopt_long(argc, argv, "i:o:d:t:v::b::h::", l_opts, NULL)) != -1)
    {
        switch (opt)
        {
            case 'i': 
                args->input_file = optarg; 
                req_args[0] = 1;
                break;
            case 'o': 
                args->output_file = optarg; 
                req_args[1] = 1;
                break;
            case 'd': 
                args->dt = atof(optarg); 
                req_args[2] = 1;
                break;
            case 't': 
                args->theta = atof(optarg); 
                req_args[3] = 1;
                break;
            case 'v': 
                args->verbose = true; 
                break;
            case 'b': 
                args->brute = true; 
                break;
            case 'h': 
                args->help = true;
                break;
            case ':':
                printf("%s: option -%c requires an argument.\n", argv[0], optopt);
                exit(1);
            default:
                break;
        }
    }

    if (args->help)
    {
        printf("Usage:\n");
        printf("\t--input or -i <input_file>\n");
        printf("\t--output or -o <output_file>\n");
        printf("\t--theta or -t <theta>\n");
        printf("\t--dt or -d <timestep>\n");
        printf("\t[Optional] --brute or -b <brute_force>\n");
        exit(0);
    }

    for (int i = 0; i < REG_ARG_COUNT; ++i)
    {
        if (req_args[i] == 0)
        {
            printf("[ERROR] Incomplete arguments\n");
            printf("Usage:\n");
            printf("\t--input or -i <input_file>\n");
            printf("\t--output or -o <output_file>\n");
            printf("\t--theta or -t <theta>\n");
            printf("\t--dt or -d <timestep>\n");
            printf("\t[Optional] --brute or -b <brute_force>\n");
            printf("\t[Optional] --verbose or -v <verbose>\n");
            printf("\t[Optional] --help or -h <help>\n");
            exit(0);
        }
    }
}

void input_particles(Particle** particles, struct args_t args)
{
    int n_particles = 0;
    *particles = (Particle*) malloc(sizeof(Particle) * n_particles);
}
