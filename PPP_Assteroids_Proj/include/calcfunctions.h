#ifndef CALCFUNCTIONS_H
#define CALCFUNCTIONS_H
#include <random>
#include <memory>
#include <vector>
#include "Vec4.h"

///\file CalcFunctions.h
/// \author Chengyan Zhang (Eric)
/// \version 1.0
/// \date Last Revision 06/05/2017 \n

/// Revision History : \n

///\brief For generating a random numeric value between upper and lower bound
/// @param[in] _min - lower bound for rng
/// @param[in] _max - upper bound for rng
float rng(const double _min,const double _max);

///\brief For returning a Vec4 type with random numeric values generated by the function stated above
/// \param[in] _min - lower bound Vec4 for rng
/// \param[in] _max - upper bound Vec4 for rng
Vec4 randomVector( const Vec4 _min, const Vec4 _max );

#endif // CALCFUNCTIONS_H
