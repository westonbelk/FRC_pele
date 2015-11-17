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

// 
const uint32_t c_jsDeadzone = 0.05;

#endif
