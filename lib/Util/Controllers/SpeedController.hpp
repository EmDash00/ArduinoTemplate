//
// Created by emdash00 on 8/3/19.
//

#ifndef ARDUINO_TEMPLATE_SPEEDCONTROLLER_HPP
#define ARDUINO_TEMPLATE_SPEEDCONTROLLER_HPP

#include "PIDController.hpp"
#include "FeedforwardController.hpp"

class SpeedController
{
public:
    explicit SpeedController(PIDController &forwardPIDController,
                             FeedforwardController &forwardFeedForwardController,
                             FeedforwardController &backwardFeedForwardController)

                             : m_pidController(forwardPIDController),
                               m_forwardFeedforwardController(forwardFeedForwardController),
                               m_backwardFeedforwardController(backwardFeedForwardController) { }

    void Update(double, double);

    void Set(double);
    double Get();

private:
    PIDController &m_pidController;
    FeedforwardController &m_forwardFeedforwardController, &m_backwardFeedforwardController;

    double m_setpoint = 0.0, m_output = 0.0;

};


#endif //ARDUINO_TEMPLATE_SPEEDCONTROLLER_HPP
