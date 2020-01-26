//
// Created by emdash00 on 10/26/19.
//

#ifndef PENDULUM_MOTOR1_HPP
#define PENDULUM_MOTOR1_HPP

#include <Arduino.h>
#include "../../Util/Util.h"

class Motor1
{
public:
    explicit Motor1(const long pwmPin, const long dirPin) :
    m_pwmPin(pwmPin), m_dirPin(dirPin){ }

    void Init();
    void Set(double duty);
    void Stop();

private:
    long m_pwmPin, m_dirPin;
};


#endif //PENDULUM_MOTOR1_HPP
