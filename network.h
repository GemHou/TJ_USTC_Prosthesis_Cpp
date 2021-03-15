//
// Created by gemhou on 2021/3/14.
//

#ifndef PROSTHESIS_CPP_NETWORK_H
#define PROSTHESIS_CPP_NETWORK_H

#endif //PROSTHESIS_CPP_NETWORK_H

void generate_b(int y_size, double *b);
void generate_w(int y_size, int x_size, double *w);
void generate_wb(int x_size, int x1_size, int x2_size, int y_size, double *b1, double *b2, double *b3, double *w1,
                 double *w2, double *w3);
void generate_x(int , double *);
void network_forward(int x_size, int x1_size, int x2_size, int y_size, double *x1, double *x2, double *y, double *b1,
                     double *b2, double *b3, const double *w1, const double *w2, const double *w3, double *x);
