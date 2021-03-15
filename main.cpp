#include <iostream>
#include "network.h"
#include "list.h"
#include "read_wb.h"

int main()
{
    int x_size = 18;
    int x1_size = 256;
    int x2_size = 256;
    int y_size = 6;
    double x1[x1_size];
    double x2[x2_size];
    double y[y_size];
    /*
    double b1[x1_size];
    double b2[x2_size];
    double b3[y_size];
    double w1[x1_size][x_size];
    double w2[x2_size][x1_size];
    double w3[y_size][x2_size];
    generate_wb(x_size, x1_size, x2_size, y_size, b1, b2, b3, (double *) w1, (double *) w2, (double *) w3);
    */

    double b1[256];
    double b2[256];
    double b3[256];
    double w1[256][18];
    double w2[256][256];
    double w3[6][256];
    read_wb(b1, b2, b3, (double*)w1, (double*)w2, (double*)w3);

    cout << "Start..." << endl;
    for(int loop_i = 0; loop_i < 1; loop_i++)
    {
        // double x[x_size];
        // generate_x(x_size, x);
        double x[18] = {0.0, 0.0, 0.0, -0.0, -0.6860127449035645, 0.0, 0.9540787935256958, 0.0, 0.19549477100372314, 0.0,
                -0.6937729120254517, 0.0, 1.0145938396453857, 0.0, 0.2897615134716034, 0.0, 0.0, 0.0};
        print_list(x, x_size, "x");

        network_forward(x_size, x1_size, x2_size, y_size, x1, x2, y,
                        b1, b2, b3, (double*)w1, (double*)w2, (double*)w3, x);
        print_list(y, y_size, "y");
    }
    cout << "Finish......";
    return 0;
}
