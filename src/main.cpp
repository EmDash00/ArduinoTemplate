//
// Created by emdash00 on 7/22/19.
//

#include <../lib/System/System.hpp>
#include "TimerOne.h"

void setup()
{
    System::GetInstance().Setup();

    Timer1.initialize(1/UPDATE_FREQUENCY);
    Timer1.attachInterrupt(System::Update);
}

void loop()
{
    System::GetInstance().Run();
}
