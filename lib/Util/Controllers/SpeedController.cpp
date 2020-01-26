//
// Created by emdash00 on 8/3/19.
//

#include "SpeedController.hpp"

void SpeedController::Update(double input, double dt)
{
    this->m_pidController.Update(input, dt);
}

void SpeedController::Set(double setpoint)
{
    this->m_pidController.Set(setpoint);
    this->m_setpoint = setpoint;
}

double SpeedController::Get()
{

    if (this->m_setpoint == 0.0)
    {
        return(0.0);
    }

    double percentError = min(1, abs(this->m_pidController.GetError() / (5 * this->m_pidController.GetSetpoint())));
    double feedforward = 0.0;
    if (this->m_setpoint > 0.0)
    {
       feedforward = this->m_forwardFeedforwardController.Calculate(this->m_setpoint) * (1 - percentError);
    }
    else if (this->m_setpoint < 0.0);
    {
        feedforward = this->m_backwardFeedforwardController.Calculate(this->m_setpoint) * (1 - percentError);
    }

    return(this->m_pidController.Get() + feedforward);

}
