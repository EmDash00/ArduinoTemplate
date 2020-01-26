//
// Created by emdash00 on 9/1/19.
//

#include "Command.hpp"

bool Command::shouldRun(unsigned long time)
{
    bool run = super::shouldRun(time);

    if (!this->m_completedSetup && run)
    {
        this->m_completedSetup = true;
        this->Setup();
    }

    return run;
}




