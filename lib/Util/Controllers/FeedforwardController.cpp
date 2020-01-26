//
// Created by emdash00 on 8/3/19.
//

#include "FeedforwardController.hpp"

double FeedforwardController::Calculate(double x)
{
    return (this->m_proportion * x + this->m_offset);
}
