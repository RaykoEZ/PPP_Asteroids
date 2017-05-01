#ifndef ASTEROIDS_H
#define ASTEROIDS_H
#include <iostream>
#include "GameObjects.h"
#include "CalcFunctions.h"
class Asteroids : public GameObjects
{
public:


    Asteroids():GameObjects(){;}

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

    Asteroids(const Asteroids &_obj):
              GameObjects(randomVector(Vec4(-1.0f,-1.0f,0.0f,1.0f),Vec4(0.5f,0.f,0.0f,1.0f)),
                                       _obj.m_position,
                                       rng(_obj.getVelo(),_obj.getVelo()+0.1f),0.0f,
                                       rng(2.0f,6.0f),
                                       rng(1.0f,_obj.getSize()),
                                       asteroidType){;}


    ~Asteroids()
    {
        //std::cout<<"Asteroid Destroyed."<<'\n';
    }



};

#endif // ASTEROIDS_H
