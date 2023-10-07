#ifndef EDGE_H
#define EDGE_H

struct Edge {
    int from;
    int to;
    float data;
    Edge(int set_from, int set_to, float set_data);
};

#endif
