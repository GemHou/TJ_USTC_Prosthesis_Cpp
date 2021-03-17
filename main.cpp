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

    // double x[x_size];
    double x[18] = {0.0, 0.0, 0.0, -0.0, -0.6860127449035645, 0.0, 0.9540787935256958, 0.0, 0.19549477100372314, 0.0,
                    -0.6937729120254517, 0.0, 1.0145938396453857, 0.0, 0.2897615134716034, 0.0, 0.0, 0.0};
    double input_z_p_init_z;
    double input_vx;
    double input_vz;
    double input_pitch;
    double input_prosthesis_hip_pos;
    double input_prosthesis_hip_vel;
    double input_prosthesis_knee_pos;
    double input_prosthesis_knee_vel;
    double input_prosthesis_ankle_pos;
    double input_prosthesis_ankle_vel;
    double input_healthy_hip_pos;
    double input_healthy_hip_vel;
    double input_healthy_knee_pos;
    double input_healthy_knee_vel;
    double input_healthy_ankle_pos;
    double input_healthy_ankle_vel;
    double input_prosthesis_feet_contact;
    double input_healthy_feet_contact;

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
    for(int loop_i = 0; loop_i < loop_i + 1; loop_i++)  // the "loop_i + 1" can be replaced with a constant
    {
        cout << "iteration: " << loop_i << endl;

        // ------ please update the sensor information here ------
        input_z_p_init_z = -0.06;  // for example, unit: meters, positive direction: up
        input_vx = 0.6;  // unit: meters/second, positive direction: forward
        input_vz = 0;  // unit: meters/second, positive direction: up
        input_pitch = -0.3;  // unit: radians, positive direction: forward
        input_prosthesis_hip_pos = 0;  // unit: degree, positive direction: forward
        input_prosthesis_hip_vel = 0;  // unit: degree/second, positive direction: forward
        input_prosthesis_knee_pos = 0;  // unit: degree, positive direction: forward
        input_prosthesis_knee_vel = 0;  // unit: degree/second, positive direction: forward
        input_prosthesis_ankle_pos = 0;  // unit: degree, positive direction: up
        input_prosthesis_ankle_vel = 0;  // unit: degree/second, positive direction: up
        input_healthy_hip_pos = 0;  // unit: degree, positive direction: forward
        input_healthy_hip_vel = 0;  // unit: degree/second, positive direction: forward
        input_healthy_knee_pos = 0;  // unit: degree, positive direction: forward
        input_healthy_knee_vel = 0;  // unit: degree/second, positive direction: forward
        input_healthy_ankle_pos = 0;  // unit: degree, positive direction: up
        input_healthy_ankle_vel = 0;  // unit: degree/second, positive direction: up
        input_prosthesis_feet_contact = 1;  // 1: foot touching, 0: no touching
        input_healthy_feet_contact = 1;  // 1: foot touching, 0: no touching
        // ------ ------

        x[0] = input_z_p_init_z;
        x[1] = input_vx * 0.3;
        x[2] = input_vz * 0.3;
        x[3] = input_pitch;
        x[4] = (input_prosthesis_hip_pos - (-30)) / (150 - (-30)) * 2 - 1;
        x[5] = input_prosthesis_hip_vel / (150 - (-30)) * 2;
        x[6] = (input_prosthesis_knee_pos - (-90)) / (0 - (-90)) * 2 - 1;
        x[7] = input_prosthesis_knee_vel / (0 - (-90)) * 2;
        x[8] = (input_prosthesis_ankle_pos - (-45)) / (0 - (-45)) * 2 - 1;
        x[9] = input_prosthesis_ankle_vel / (0 - (-45)) * 2;
        x[10] = (input_healthy_hip_pos - (-30)) / (150 - (-30)) * 2 - 1;
        x[11] = input_healthy_hip_vel / (150 - (-30)) * 2;
        x[12] = (input_healthy_knee_pos - (-90)) / (0 - (-90)) * 2 - 1;
        x[13] = input_healthy_knee_vel / (0 - (-90)) * 2;
        x[14] = (input_healthy_ankle_pos - (-45)) / (0 - (-45)) * 2 - 1;
        x[15] = input_healthy_ankle_vel / (0 - (-45)) * 2;
        x[16] = input_prosthesis_feet_contact;
        x[17] = input_healthy_feet_contact;
        // print_list(x, x_size, "x");

        network_forward(x_size, x1_size, x2_size, y_size, x1, x2, y,
                        b1, b2, b3, (double*)w1, (double*)w2, (double*)w3, x);
        // print_list(y, y_size, "y");
    }
    cout << "Finish......";
    return 0;
}
