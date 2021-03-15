//
// Created by gemhou on 2021/3/15.
//

#include "network.h"
#include <math.h>
#include <iostream>
#include "list.h"

using namespace std;

void multiple_list(double *x, int x_size, double *w, int y_size, double *y)
{
    for(int j=0; j < y_size; j++)
    {
        y[j] = 0;
        for (int i = 0; i < x_size; i++)
        {
            y[j] += w[j*x_size+i] * x[i];
        }
    }
}


void add_list(double *b, int y_size, double *y)
{
    for(int j=0; j < y_size; j++)
    {
        y[j] += b[j];
    }
}


void relu_list(double *y, int y_size)
{
    for(int j=0; j < y_size; j++)
    {
        if(y[j]<0)
            y[j] = 0;
    }
}


void tanh_list(double *y, int y_size)
{
    for(int j=0; j < y_size; j++)
    {
        y[j] = tanh(y[j]);
    }
}


void print_list(double *y, int y_size, string y_name)
{
    cout << y_name << ": [";
    for(int j=0; j < y_size; j++)
    {
        cout << y[j] << ", ";
    }
    cout << "]" << endl;
}


void transform_list(double *x, int j_size, int i_size, double *y)
{
    for(int j=0; j<j_size; j++)
    {
        for(int i=0; i<i_size; i++)
        {
            y[i*j_size+j] = x[j*i_size+i];
        }
    }
}

void copy_list(double *e, double *f, int size)
{
    for(int i=0; i<size; i++)
    {
        e[i] = f[i];
    }
}
