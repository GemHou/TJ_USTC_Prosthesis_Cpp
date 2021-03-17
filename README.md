# TJ_USTC_Prosthesis_Cpp
TJ_USTC_Prosthesis_Cpp

## Run
1. modify the sensor input interface and motor output interface in line 109 and 142 of main.cpp.

2. run main.cpp

## Variables Meaning
        input_z_p_init_z: the "current gravity center height" minus the "initial upright gravity center height", unit: meters, positive direction: up
        input_vx: the vlocity in the forward dirction, unit: meters/second, positive direction: forward
        input_vz: the vlocity in the upward dirction, unit: meters/second, positive direction: up
        input_pitch: unit: radians, positive direction: forward
        input_prosthesis_hip_pos: unit: degree, positive direction: forward
        input_prosthesis_hip_vel: unit: degree/second, positive direction: forward
        input_prosthesis_knee_pos: unit: degree, positive direction: forward
        input_prosthesis_knee_vel: unit: degree/second, positive direction: forward
        input_prosthesis_ankle_pos: unit: degree, positive direction: up
        input_prosthesis_ankle_vel: unit: degree/second, positive direction: up
        input_healthy_hip_pos: unit: degree, positive direction: forward
        input_healthy_hip_vel: unit: degree/second, positive direction: forward
        input_healthy_knee_pos: unit: degree, positive direction: forward
        input_healthy_knee_vel: unit: degree/second, positive direction: forward
        input_healthy_ankle_pos: unit: degree, positive direction: up
        input_healthy_ankle_vel: unit: degree/second, positive direction: up
        input_prosthesis_feet_contact: 1: foot touching, 0: no touching
        input_healthy_feet_contact: 1: foot touching, 0: no touching

        output_prosthesis_knee_power: continuous change between -1~1, corresponds to 100% power forward and -100% backward of the motor
        output_prosthesis_ankle_power: continuous change between -1~1 , corresponds to 100% power forward and -100% backward of the motor
