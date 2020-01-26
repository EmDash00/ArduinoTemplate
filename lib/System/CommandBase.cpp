//
// Created by emdash00 on 8/31/19.
//

#include "CommandBase.hpp"


void CommandBase::Init()
{
    pinMode(MR_SENSOR_PIN, INPUT); // set MR sensor pin to be an input
    pinMode(FSR_SENSOR_PIN, INPUT); // set FSR sensor pin to be an input

    pinMode(MOTOR1_PWM_PIN, OUTPUT);  // PWM pin for motor A
    pinMode(MOTOR1_DIR_PIN, OUTPUT);  // dir pin for motor A
}

