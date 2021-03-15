//
// Created by gemhou on 2021/3/15.
//

#ifndef PROSTHESIS_CPP_LIST_H
#define PROSTHESIS_CPP_LIST_H

#endif //PROSTHESIS_CPP_LIST_H

#include <iostream>

using namespace std;

void multiple_list(double *x, int x_size, double *w, int y_size, double *y);
void add_list(double *b, int y_size, double *y);
void relu_list(double *y, int y_size);
void tanh_list(double *y, int y_size);
void print_list(double *y, int y_size, string y_name);
void transform_list(double *x, int j_size, int i_size, double *y);
void copy_list(double *e, double *f, int size);
