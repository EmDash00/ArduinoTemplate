//
// Created by emdash00 on 7/29/19.
//

#include "CycleTimer.hpp"

CycleTimer::CycleTimer(double interval, bool paused) : Timer(paused)
{
   this->m_interval = interval;
}

CycleTimer::CycleTimer(double interval) : Timer(false)
{
    this->m_interval = interval;
}

double CycleTimer::Elapsed()
{
    if (this->_paused)
    {
        return(this->m_mem);
    }

    this->m_cycles = (micros() - this->m_t0) * 1E-6 / this->m_interval + this->m_mem;
    return(this->m_cycles);
}

double CycleTimer::ElapsedDiscrete()
{
    return floor(this->Elapsed());
}

bool CycleTimer::Tick()
{
    return(floor(this->m_cycles) < this->ElapsedDiscrete());
}

void CycleTimer::Synchronize()
{
    while (!this->Tick());
}



