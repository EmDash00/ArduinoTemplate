//
// Created by emdash00 on 8/3/19.
//

#ifndef ARDUINO_TEMPLATE_POSITIONCONTROLLER_HPP
#define ARDUINO_TEMPLATE_POSITIONCONTROLLER_HPP

#include "PIDController.hpp"
#include "SpeedController.hpp"

class PositionController
{
public:
    explicit PositionController(PIDController &feedbackController, SpeedController &speedController)
        : m_feedbackController(feedbackController), m_speedController(speedController) { }

    void Update(double, double);

    void Set(double);
    double Get();

private:
    PIDController &m_feedbackController;
    SpeedController &m_speedController;

    double m_output = 0.0;

};


#endif //ARDUINO_TEMPLATE_POSITIONCONTROLLER_HPP
