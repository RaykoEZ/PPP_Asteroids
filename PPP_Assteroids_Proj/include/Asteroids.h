#ifndef ASTEROIDS_H
#define ASTEROIDS_H
#include <iostream>
#include "GameObjects.h"
#include "CalcFunctions.h"

/// \file Asteroids.h
/// \author Chengyan Zhang (Eric)
/// \version 1.0
/// \date Last Revision 06/05/2017 \n

/// Revision History : \n


/// \class Asteroids
/// \brief Class for Constructing generic "asteroids"
/// \todo None yet.

class Asteroids : public GameObjects
{
public:

    ///\brief default ctor
    Asteroids():GameObjects(){;}

    ///\brief ctor for making a randomized asteroid object
    /// @param[in] _dirMin - minimum direction for direction randomizer
    /// @param[in] _dirMax - maximum direction for direction randomizer
    /// @param[in] _posMin - minimum position for position randomizer
    /// @param[in] _posMax - maximum position for position randomizer
    /// @param[in] _vMin - minimum speed for speed randomizer
    /// @param[in] _vMax - maximum speed for speed randomizer
    /// @param[in] _rot - set rotation
    /// @param[in] _rotSpdMin - minimum rotation speed for rotSpd randomizer
    /// @param[in] _rotSpdMax - maximum rotation speed for rotSpd randomizer
    /// @param[in] _size - size modifier
    Asteroids(Vec4 _dirMin,Vec4 _dirMax,
              Vec4 _posMin, Vec4 _posMax,
              float _vMin,float _vMax,
              float _rot,
              float _rotSpdMin,float _rotSpdMax,
              float _size):
              GameObjects(randomVector(_dirMin,_dirMax),
                          randomVector(_posMin,_posMax),
                          rng(_vMin,_vMax),
                          _rot,
                          rng(_rotSpdMin,_rotSpdMax),_size,asteroidType){;}

    ///\brief copy ctor for splitting asteroids
    /// @param[in] _obj - asteroid object for this copy ctor's reference
    Asteroids(const Asteroids &_obj):
              GameObjects(randomVector(Vec4(-0.8f,-0.8f,0.0f,1.0f),Vec4(0.8f,0.8f,0.0f,1.0f)),
                                       _obj.m_position,
                                       rng(_obj.m_velocity,_obj.m_velocity+0.2f),0.0f,
                                       rng(2.0f,6.0f),
                                       rng(1.0f,_obj.getSize()),
                                       asteroidType){;}

    ///\brief default dtor
    ~Asteroids()
    {
        //std::cout<<"Asteroid Destroyed."<<'\n';
    }



};

#endif // ASTEROIDS_H
