//
// Created by emdash00 on 10/26/19.
//

#include "Motor1.hpp"

void Motor1::Init()
{
    SetPWMFreqency(this->m_pwmPin, 1);
    pinMode(this->m_pwmPin, OUTPUT);
    pinMode(this->m_dirPin, OUTPUT);
}
