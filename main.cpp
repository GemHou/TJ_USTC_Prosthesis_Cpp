#include <iostream>
#include "network.h"
#include "list.h"
#include "read_wb.h"

#define X_SIZE 15

void update_x(double *x, double input_z_p_init_z, double input_vx, double input_vz, double input_pitch,
              double input_prosthesis_hip_pos, double input_prosthesis_hip_vel, double input_prosthesis_knee_pos,
              double input_prosthesis_knee_vel, double input_prosthesis_ankle_pos, double input_prosthesis_ankle_vel,
              double input_healthy_hip_pos, double input_healthy_hip_vel, double input_healthy_knee_pos,
              double input_healthy_knee_vel, double input_healthy_ankle_pos, double input_healthy_ankle_vel,
              double input_prosthesis_feet_contact, double input_healthy_feet_contact) {
    if(X_SIZE==18)
    {
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
    }
    else if(X_SIZE==15)
    {
        double x0, x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12, x13, x14;
        double hip_up = +60;
        double hip_low = -30;
        double knee_up = 0;
        double knee_low = -75;
        double ankle_up = 25;
        double ankle_low = -45;
        x0 = input_vx * 0.3;
        x1 = input_vz * 0.3;
        x2 = input_pitch;
        x3 = (input_prosthesis_hip_pos - hip_low) / (hip_up - hip_low) * 2 - 1;
        x4 = input_prosthesis_hip_vel / (hip_up - hip_low) * 2;
        x5 = (input_prosthesis_knee_pos - knee_low) / (knee_up - knee_low) * 2 - 1;
        x6 = input_prosthesis_knee_vel / (knee_up - knee_low) * 2;
        x7 = (input_prosthesis_ankle_pos - ankle_low) / (ankle_up - ankle_low) * 2 - 1;
        x8 = input_prosthesis_ankle_vel / (ankle_up - ankle_low) * 2;
        x9 = (input_healthy_hip_pos - hip_low) / (hip_up - hip_low) * 2 - 1;
        x10 = input_healthy_hip_vel / (hip_up - hip_low) * 2;
        x11 = (input_healthy_knee_pos - knee_low) / (knee_up - knee_low) * 2 - 1;
        x12 = input_healthy_knee_vel / (knee_up - knee_low) * 2;
        x13 = (input_healthy_ankle_pos - ankle_low) / (ankle_up - ankle_low) * 2 - 1;
        x14 = input_healthy_ankle_vel / (ankle_up - ankle_low) * 2;

        x[0] = x0;
        x[1] = x1;
        x[2] = x2;
        x[3] = x3;
        x[4] = x4;
        x[5] = x5;
        x[6] = x6;
        x[7] = x7;
        x[8] = x8;
        x[9] = x9;
        x[10] = x10;
        x[11] = x11;
        x[12] = x12;
        x[13] = x13;
        x[14] = x14;
    }
}

void
reinforcement_learning_decision(int x_size, int x1_size, int x2_size, int y_size, double *x, double input_z_p_init_z,
                                double input_vx, double input_vz, double input_pitch, double input_prosthesis_hip_pos,
                                double input_prosthesis_hip_vel, double input_prosthesis_knee_pos,
                                double input_prosthesis_knee_vel, double input_prosthesis_ankle_pos,
                                double input_prosthesis_ankle_vel, double input_healthy_hip_pos,
                                double input_healthy_hip_vel, double input_healthy_knee_pos,
                                double input_healthy_knee_vel, double input_healthy_ankle_pos,
                                double input_healthy_ankle_vel, double input_prosthesis_feet_contact,
                                double input_healthy_feet_contact, double *x1, double *x2, double *y, double *b1,
                                double *b2, double *b3, const double *w1, const double *w2, const double *w3,
                                double &output_prosthesis_knee_position, double &output_prosthesis_ankle_position) {
    update_x(x, input_z_p_init_z, input_vx, input_vz, input_pitch, input_prosthesis_hip_pos,
             input_prosthesis_hip_vel,
             input_prosthesis_knee_pos, input_prosthesis_knee_vel, input_prosthesis_ankle_pos,
             input_prosthesis_ankle_vel,
             input_healthy_hip_pos, input_healthy_hip_vel, input_healthy_knee_pos, input_healthy_knee_vel,
             input_healthy_ankle_pos, input_healthy_ankle_vel, input_prosthesis_feet_contact,
             input_healthy_feet_contact);
    /**/
    double x_test[15] = { 0.0069542839191854 ,  0.01652679033577442 ,  -0.041296642273664474 ,  -0.996933102607727 ,  0.003369022160768509 ,  1.0198657512664795 ,  -0.012619017623364925 ,  1.0212688446044922 ,  -0.013889503665268421 ,  0.22839857637882233 ,  -0.085178904235363 ,  -0.22689631581306458 ,  0.1583538055419922 ,  0.7940875291824341 ,  0.03594062104821205 ,  };
    x = x_test;

    print_list(x, x_size, "x");

    network_forward(x_size, x1_size, x2_size, y_size, x1, x2, y,
                    b1, b2, b3, (double*)w1, (double*)w2, (double*)w3, x);
    print_list(y, y_size, "y");
    output_prosthesis_knee_position = y[1];
    output_prosthesis_ankle_position = y[2];
}

int main()
{
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

    double output_prosthesis_knee_position;  // -1~1, corresponds to 100% position forward and -100% backward of the motor
    double output_prosthesis_ankle_position;  // -1~1 , corresponds to 100% position forward and -100% backward of the motor

    int x_size = 15;
    int x1_size = 256;
    int x2_size = 256;
    int y_size = 6;

    double x[x_size];  //  = {0.0, 0.0, 0.0, -0.0, -0.6860127449035645, 0.0, 0.9540787935256958, 0.0,
    // 0.19549477100372314, 0.0, -0.6937729120254517, 0.0, 1.0145938396453857, 0.0, 0.2897615134716034, 0.0, 0.0, 0.0}
    double x1[x1_size];
    double x2[x2_size];
    double y[y_size];

    double b1[x1_size];
    double b2[x2_size];
    double b3[y_size];
    double w1[x1_size][x_size];
    double w2[x2_size][x1_size];
    double w3[y_size][x2_size];

    if(X_SIZE==15)
    {
        // read_wb_15(b1, b2, b3, (double*)w1, (double*)w2, (double*)w3);
        read_wb_15_stand(b1, b2, b3, (double*)w1, (double*)w2, (double*)w3);
        cout << "X_SIZE==15" << endl;
    }
    else if(X_SIZE==18)
    {
        // read_wb_18((double*)b1, (double*)b2, (double*)b3, (double*)w1, (double*)w2, (double*)w3);
        cout << "X_SIZE==18" << endl;
    }
    else
    {
        cout << "X_SIZE unknown" << endl;
    }


    // cout << "Start..." << endl;
    for(int loop_i = 0; loop_i < loop_i + 1; loop_i++)  // the "loop_i + 1" can be replaced with a constant
    {
        // cout << "iteration: " << loop_i << endl;

        // ------ please update the sensor information here ------
        input_z_p_init_z = -0.06;  // for example, unit: meters, positive direction: up
        input_vx = 0;  // unit: meters/second, positive direction: forward
        input_vz = 0;  // unit: meters/second, positive direction: up
        input_pitch = -0.04;  // unit: radians, positive direction: forward
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

        reinforcement_learning_decision(x_size, x1_size, x2_size, y_size, x, input_z_p_init_z, input_vx, input_vz,
                                        input_pitch, input_prosthesis_hip_pos,
                                        input_prosthesis_hip_vel, input_prosthesis_knee_pos, input_prosthesis_knee_vel,
                                        input_prosthesis_ankle_pos,
                                        input_prosthesis_ankle_vel, input_healthy_hip_pos, input_healthy_hip_vel,
                                        input_healthy_knee_pos,
                                        input_healthy_knee_vel, input_healthy_ankle_pos, input_healthy_ankle_vel,
                                        input_prosthesis_feet_contact,
                                        input_healthy_feet_contact, x1, x2, y, b1, b2, b3, (double*)w1, (double*)w2, (double*)w3,
                                        output_prosthesis_knee_position,
                                        output_prosthesis_ankle_position);

        cout << "output_prosthesis_knee_position: " << output_prosthesis_knee_position << endl;  // -1~1, corresponds to 100% position forward and -100% backward of the motor
        cout << "output_prosthesis_ankle_position: " << output_prosthesis_ankle_position << endl << endl;  // -1~1 , corresponds to 100% position forward and -100% backward of the motor
    }
    cout << "Finish......";
    return 0;
}
