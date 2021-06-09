//
// Created by gemhou on 2021/3/14.
//

#include <math.h>
#include <iostream>
#include "list.h"
// #include "network.h"

void generate_b(int y_size, double *b)  // ,
{
    for(int j=0; j < y_size; j++)
    {
        b[j] = j;
    }
}

void generate_w(int y_size, int x_size, double *w)  // ,
{
    for(int j=0; j<y_size; j++)
    {
        for(int i=0; i < x_size; i++)
        {
            w[j*x_size+i] = i+j;
        }
    }
}

void generate_wb(int x_size, int x1_size, int x2_size, int y_size, double *b1, double *b2, double *b3, double *w1,
                 double *w2, double *w3)
{
    generate_b(x1_size, b1);
    generate_b(x2_size, b2);
    generate_b(y_size, b3);
    generate_w(x1_size, x_size, (double*)w1);
    generate_w(x2_size, x1_size, (double*)w2);
    generate_w(y_size, x2_size, (double*)w3);
}

void generate_x(int x_size, double *x)
{
    for(int i=0; i < x_size; i++)
    {
        x[i] = i;
    }
}




void network_forward(int x_size, int x1_size, int x2_size, int y_size, double *x1, double *x2, double *y, double *b1,
                     double *b2, double *b3, const double *w1, const double *w2, const double *w3, double *x) {
    multiple_list(x, x_size, (double*)w1, x1_size, x1);
    add_list(b1, x1_size, x1);
    // relu_list(x1, x1_size);
    print_list(x1, x1_size, "x1");

    multiple_list(x1, x1_size, (double*)w2, x2_size, x2);
    add_list(b2, x2_size, x2);
    relu_list(x2, x2_size);
    print_list(x2, x2_size, "x2");

    multiple_list(x2, x2_size, (double*)w3, y_size, y);
    add_list(b3, y_size, y);
    tanh_list(y, y_size);
}
