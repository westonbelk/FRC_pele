#ifndef _ROBOTCONSTANTS_H
#define _ROBOTCONSTANTS_H

// Drive motor ports
const uint32_t  c_flmotor_PWMid = 0;
const uint32_t  c_rlmotor_PWMid = 2;
const uint32_t  c_frmotor_PWMid = 1;
const uint32_t  c_rrmotor_PWMid = 4;

// Drive motor inversion states
const bool c_kflmotor_inversed = false;
const bool c_krlmotor_inversed = false;
const bool c_kfrmotor_inversed = true;
const bool c_krrmotor_inversed = true;

// Feeder subsystem motors
const uint32_t c_feedermotor_PWMid = 7;
const uint32_t c_loadermotor_PWMid = 5;
const uint32_t c_shootermotor1_PWMid = 6;
const uint32_t c_shootermotor2_PWMid = 3;

// Joystick buttons
const uint32_t c_jsthumb_buttonid = 2;


#endif
