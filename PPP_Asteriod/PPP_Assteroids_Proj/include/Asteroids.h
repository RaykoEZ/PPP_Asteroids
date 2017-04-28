#ifndef ASTEROIDS_H
#define ASTEROIDS_H
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
    ~Asteroids(){;}



};

#endif // ASTEROIDS_H
