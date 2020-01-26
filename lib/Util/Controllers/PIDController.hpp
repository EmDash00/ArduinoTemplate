//
// Created by emdash00 on 7/22/19.
//

#ifndef CLIONPROJECTS_PIDFCONTROLLER_HPP
#define CLIONPROJECTS_PIDFCONTROLLER_HPP

#include <Arduino.h>
#include "../math/statistics.h"

enum class DerivativeCalc
{
    DIRECT,
    EXTRAPOLATE
};

class PIDController
{
public:
    explicit PIDController(double k_P, double k_I, double k_D) : m_k_P(k_P), m_k_I(k_I), m_k_D(k_D) { }

    void SetContinuous(bool);
    void Set(double);
    void SetOutputRange(double, double);
    void SetInputRange(double, double);

    void SetAbsoluteTolerance(double); //Sets tolerance in an range about your setpoint
    void SetPercentTolerance(double); //Sets tolerance in a range about your setpoint. The range is a percent of your setpoint
    void SetStatisticalTolerance(double, double); //Sets tolerance given the amount of certainty you want to have that you are actually near your target. Most robust.

    double GetError(); //Gets the error (setpoint - current sensor value)
    double GetSetpoint(); //Gets the value of the setpoint

    bool OnTarget(); //Tells you whether the PIDController is within the set tolerance.

    void Reset();
    void ResetAccumulatedError();
    void Update(double, double, DerivativeCalc=DerivativeCalc::EXTRAPOLATE);

    double Get();

private:
    bool m_continuous = false;

    double
            m_k_P,
            m_k_I,
            m_k_D;

    double m_setpoint = 0.0, m_deadband = 0.0;

    double
            m_minInput = 0.0,
            m_maxInput = 0.0,
            m_minOutput = 0.0,
            m_maxOutput = 0.0,
            m_proportionalMin = 0.0,
            m_proportaionalMax = 0.0,
            m_tolerance = 0.0;

    double m_output = 0.0;

    double
            m_accumulatedError = 0.0,
            m_lastError = 0.0,
            m_error = 0.0;



    enum class ToleranceType {
        ABSOLUTE,
        PERCENT,
        STATISTICAL
    } m_toleranceType;



};

#endif //CLIONPROJECTS_PIDFCONTROLLER_HPP
