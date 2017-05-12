#include <iostream>
#include "CalcFunctions.h"

///\file CalcFunctions.cpp

float rng(const double _min,const double _max)
{
    //using mersenne_twister_engine for rng generation
    std::mt19937 r;
    //setting seed
    std::random_device seedF;
    r.seed(seedF());
    //even distribution of random numbers than using rand()
    std::uniform_real_distribution<double> dist(_min,_max);

    return (float)dist(r);
}

//---------------------------------------------------------------

Vec4 randomVector(const Vec4 _min, const Vec4 _max)
{
    //calling rng for each float elements of the Vec4
    return Vec4(rng((double)_min.m_x,(double)_max.m_x),
                rng((double)_min.m_y,(double)_max.m_y),0.0f,1.0f);
}


