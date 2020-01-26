//
//d Created by emdash00 on 8/16/19.
//

#ifndef ARDUINO_TEMPLATE_SYSTEM_HPP
#define ARDUINO_TEMPLATE_SYSTEM_HPP

#include "../../lib/Util/Timer/Timer.hpp"
#include "../../lib/Util/Timer/CycleTimer.hpp"

#include "CommandBase.hpp"

#include <Thread.h>
#include <ThreadController.h>

class System
{
public:
    static System &GetInstance();

    void Setup();
    void Calibrate();
    static void Update();
    void Run();
    void End();
    bool IsFinished();

    double Time();


private:

    bool m_doRun = true;
    ThreadController m_threadController;

    CycleTimer m_updater;
    Timer m_timer;

    explicit System() : m_updater(1.0 / 60.0, true), m_timer(false) { }
};


#endif //PENDULUM_SYSTEM_HPP
