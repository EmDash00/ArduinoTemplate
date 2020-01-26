//
// Created by emdash00 on 8/3/19.
//

#include "PositionController.hpp"

void PositionController::Update(double input, double dt)
{
    this->m_feedbackController.Update(input, dt);

    this->m_speedController.Set(this->m_feedbackController.Get());
    this->m_speedController.Update(input, dt);
}

void PositionController::Set(double setpoint)
{
    this->m_feedbackController.Set(setpoint);
    this->m_feedbackController.ResetAccumulatedError();
}

double PositionController::Get()
{
    return this->m_output;
}
