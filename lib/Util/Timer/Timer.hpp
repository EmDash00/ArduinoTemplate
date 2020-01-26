//
// Created by emdash00 on 7/22/19.
//

#ifndef ARDUINO_TEMPLATE_TIMER_HPP
#define ARDUINO_TEMPLATE_TIMER_HPP

#include <Arduino.h>

class Timer
{

public:
    Timer();
    Timer(bool);

    static void Wait(double);

    double Elapsed();
    double Delta();

    void Start();
    void Stop();

    void Reset();
    void Reset(bool);

protected:
    bool _paused;

    double
        m_t0 = 0,
        m_mem = 0,
        m_tLast = 0;

};


#endif //ARDUINO_TEMPLATE_TIMER_HPP
