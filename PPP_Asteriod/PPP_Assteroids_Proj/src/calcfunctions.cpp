#include <iostream>
#include "CalcFunctions.h"

float rng(const double _min,const double _max)
{
    std::mt19937 r;
    std::random_device seedF;
    r.seed(seedF());
    std::uniform_real_distribution<double> dist(_min,_max);

    return (float)dist(r);
}

Vec4 randomVector(const Vec4 _min, const Vec4 _max)
{
    return Vec4(rng((double)_min.m_x,(double)_max.m_x),
                rng((double)_min.m_y,(double)_max.m_y),0.0f,1.0f);
}

