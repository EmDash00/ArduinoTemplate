//
// Created by emdash00 on 8/17/19.
//

#ifndef ARDUINO_TEMPLATE_SUBSYSTEM_HPP
#define ARDUINO_TEMPLATE_SUBSYSTEM_HPP

#include <Thread.h>

class Subsystem
{
public:
    Subsystem();

    virtual void periodic() = 0;

protected:
    Thread m_thread;
};


#endif //PENDULUM_SUBSYSTEM_HPP
