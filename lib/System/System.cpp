//
// Created by emdash00 on 8/16/19.
//

#include "System.hpp"


// Encoder Units: m (measuring displacement)
// Analog Pot Units: radians (measuring angular deflection)

System& System::GetInstance()
{
   static System INSTANCE;

   return INSTANCE;
}

void System::Calibrate()
{

}

void System::Setup()
{
    // Run this method in arduino setup. Register your commands to the thread manager here.
    CommandBase::Init();
    this->Calibrate();

    this->m_threadController.setInterval(10);

    this->m_updater.Start();
    this->m_timer.Reset();
}

// Method runs on an interrupt on TimerOne. Put subsystems that need updating to mantain state here.
void System::Update()
{
    static double lastTime = 0.0;

    double dt = (millis() - lastTime) / 1000.0;
    lastTime = millis();

}

// Put this method in arduino loop
void System::Run()
{
    this->m_threadController.run();
}

bool System::IsFinished()
{
    // Check at the start of Run every time it's called. If false, sets m_doRun to false and calls end.
    // The recommended way to do this is when the ThreadController is empty. That happens after every thread HALTs

    return false;
}

void System::End()
{
    // Clean up code for when your thing is done. Optional.

}

double System::Time()
{
    return this->m_timer.Elapsed();
}



