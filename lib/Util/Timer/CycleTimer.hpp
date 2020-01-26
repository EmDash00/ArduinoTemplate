//
// Created by emdash00 on 7/29/19.
//

#ifndef ARDUINO_TEMPLATE_CYCLETIMER_HPP
#define ARDUINO_TEMPLATE_CYCLETIMER_HPP

#include "Timer.hpp"
#include "ArduinoSTL.h"

class CycleTimer : public Timer
{
public:
    CycleTimer(double, bool);
    CycleTimer(double);

    double Elapsed();

    double ElapsedDiscrete();
    bool Tick();
    void Synchronize();

private:
    typedef Timer super;

    double m_interval;
    double m_cycles = 0;

};


#endif //ARDUINO_TEMPLATE_CYCLETIMER_HPP
