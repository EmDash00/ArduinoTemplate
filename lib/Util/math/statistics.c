//
// Created by emdash00 on 8/3/19.
//

#include "statistics.h"

float inverf(float x)
{
    const float PI = 3.14159265354;
    float tt1, tt2, lnx, sgn;
    sgn = (x < 0) ? -1.0f : 1.0f;

    x = (1 - x)*(1 + x);        // x = 1 - x*x;
    lnx = log(x);

    tt1 = 2/( PI * 0.147) + 0.5f * lnx;
    tt2 = 1/(0.147) * lnx;

    return(sgn*sqrt(-tt1 + sqrt(tt1*tt1 - tt2)));
}
