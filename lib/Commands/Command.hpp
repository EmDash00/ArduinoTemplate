//
// Created by emdash00 on 8/16/19.
//

#ifndef ARDUINO_TEMPLATE_COMMAND_HPP
#define ARDUINO_TEMPLATE_COMMAND_HPP

#include <Thread.h>
#include "../Util/math/macros.h"


class Command : public Thread
{
public:
    explicit Command(double _timeout = 0.0) : super(nullptr, 0, (long)round(_timeout * 1000.0)) { }

    virtual void Setup() = 0; //Called once before the first time run is called.

    virtual bool shouldRun(unsigned long time) override ; //Override the shouldRun method from Thread to set an endpoint for your command.

protected:
    bool m_completedSetup = false;

private:
    typedef Thread super;


};


#endif //PENDULUM_COMMANDBAE_HPP
