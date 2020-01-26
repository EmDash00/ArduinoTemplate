//
// Created by emdash00 on 7/22/19.
//

#include "Timer.hpp"

Timer::Timer(bool paused)
{
    this->_paused = paused;
    this->m_t0 = micros();
}

Timer::Timer()
{
    Timer(false);
}

void Timer::Wait(double t)
{
    auto t0 = micros();

    while((micros() - t0) / 1E6 < t) { }
}

double Timer::Elapsed()
{
    if (this->_paused)
    {
        return(this->m_mem);
    }
    else
    {
        return(this->m_tLast = (micros() - this->m_t0) / 1E6 + this->m_mem);
    }
}

double Timer::Delta()
{
    double t_nm1 = this->m_tLast;
    return (this->Elapsed() - t_nm1);
}

void Timer::Reset(bool pause)
{
    this->_paused = pause;

    this->m_mem = 0;
    this->m_t0 = micros();
}

void Timer::Reset()
{
    this->Reset(false);
}


void Timer::Start()
{
    if (this->_paused)
    {
        this->_paused = false;
        this->m_t0 = micros();
    }
}

void Timer::Stop()
{
    if (!this->_paused)
    {
        this->m_mem = this->Elapsed();
        this->_paused = true;
    }
}