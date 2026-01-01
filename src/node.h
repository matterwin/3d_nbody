#ifndef NODE_H
#define NODE_H

#include "region.h"

#define CHILDREN_PER_NODE 8

typedef struct Node 
{
    double x_min, x_max;
    double y_min, y_max;
    double center_x, center_y;

    double weighted_sum_x, weighted_sum_y;
    double total_mass;
    double com_x, com_y;

    int num_particles;
    int particle_index;

    int children[CHILDREN_PER_NODE];        // 8 regions per node
    enum Region which_region;               // region wrt parent
} Node;

#endif
