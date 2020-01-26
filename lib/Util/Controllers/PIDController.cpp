//
// Created by emdash00 on 7/22/19.
//

#include "PIDController.hpp"

double PIDController::GetError()
{
    return this->m_error;
}

double PIDController::GetSetpoint()
{
    return this->m_setpoint;
}

void PIDController::SetContinuous(bool continuous = true)
{
    this->m_continuous = continuous;
}

void PIDController::SetInputRange(double minInput, double maxInput)
{
    this->m_minInput = minInput;
    this->m_maxInput = maxInput;

    this->m_setpoint = constrain(this->m_setpoint, this->m_minInput, this->m_maxInput);
}

void PIDController::SetOutputRange(double minOutput, double maxOutput)
{
    this->m_minOutput = minOutput;
    this->m_maxOutput = maxOutput;
}

void PIDController::Set(double setpoint)
{
    if (this->m_minInput == 0 && this->m_maxInput == 0)
    {
        this->m_setpoint = setpoint;
    }
    else
    {
        this->m_setpoint = constrain(setpoint, this->m_minInput, this->m_maxInput);
    }
}

void PIDController::SetAbsoluteTolerance(double tolerance)
{
    this->m_toleranceType = ToleranceType::ABSOLUTE;
    this->m_tolerance = tolerance = tolerance;
}

void PIDController::SetPercentTolerance(double percentTolerance)
{
    this->m_toleranceType = ToleranceType::PERCENT;
    this->m_tolerance = percentTolerance * this->m_setpoint;
}

void PIDController::SetStatisticalTolerance(double confidence, double variance)
{
    this->m_toleranceType = ToleranceType ::STATISTICAL;

    double p = 1.0 - confidence;
    this->m_tolerance = erfinv(2 * p - 1) * sqrt(variance) * sqrt(2.0);
}

void PIDController::Update(double input, double input1, DerivativeCalc calc)
{
    this->m_error = this->m_setpoint - input;

    double error1;

    if (calc == DerivativeCalc::EXTRAPOLATE)
    {
        if (this->m_continuous)
        {
            if (abs(this->m_error) > (this->m_maxInput - this->m_minInput) / 2)
            {
                if (this->m_error > 0)
                {
                    this->m_error = this->m_error + (this->m_maxInput - this->m_minInput);
                }
                else
                {
                    this->m_error = this->m_error - (this->m_maxInput - this->m_minInput);
                }
            }
        }

        error1 = (this->m_error - this->m_lastError) / input1;
    }
    else if (calc == DerivativeCalc::DIRECT)
    {
        error1 = input1;
    }
    this->m_lastError = this->m_error;

    if (this->m_k_P * this->m_error < this->m_maxOutput && this->m_k_P * this->m_error > this->m_minOutput)
    {
        this->m_accumulatedError += this->m_error;
    }
    else
    {
        this->m_accumulatedError = 0;
    }

    double proportionalError = (proportionalError < this->m_deadband ? 0 : this->m_error);

    double output = this->m_k_P * proportionalError +
                    this->m_k_I * this->m_accumulatedError +
                    this->m_k_D * input1;

    if (!(this->m_minOutput == 0 && this->m_maxOutput == 0))
    {
        this->m_output = constrain(output, this->m_minOutput, this->m_maxOutput);
    }

}

void PIDController::Reset()
{
    this->m_error = 0.0;
    this->m_accumulatedError = 0.0;
    this->m_lastError = 0.0;
}

void PIDController::ResetAccumulatedError()
{
    this->m_accumulatedError = 0.0;
}

double PIDController::Get()
{
    return this->m_output;
}

bool PIDController::OnTarget()
{
    if (this->m_toleranceType == ToleranceType::STATISTICAL || this->m_toleranceType == ToleranceType::ABSOLUTE){
        return (abs(this->m_error) < this->m_tolerance);
    }
    else if (this->m_toleranceType == ToleranceType::PERCENT)
    {
        return (abs(this->m_error) < (this->m_tolerance * this->m_setpoint));
    }

}


