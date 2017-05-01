#ifndef GAMEOBJECTS_H
#define GAMEOBJECTS_H
#include "Vec4.h"
#include <cmath>
#ifdef WIN32
  #include <Windows.h> // must be before gl.h include
#endif

#if defined (__linux__) || defined (WIN32)
    #include <GL/gl.h>
#endif
#ifdef __APPLE__
    #include <OpenGL/gl.h>
#endif

float degree();
float radian();
void shipType(const float _size);
void bulletType(const float _size);
void asteroidType(const float _size);
class GameObjects
{


public:

    virtual ~GameObjects(){;}
    typedef void (*Shape)(const float _size);
    void rotateMe(bool _left,float _rotDeg);
    void forward(Shape _type);
    void move(float _step);
    void drawMe(Shape _type,float &_x,float &_y, float _rot);
    float getVelo()const{return m_velocity;}
    float getSize()const{return m_size;}
    Shape m_shapeType;

    Vec4 m_position;
    Vec4 m_direction;

    GameObjects():
                m_size(0.75f),
                m_shapeType(shipType),
                m_velocity(0.0f),
                m_rot(0.0f),
                m_rotSpd(5.5f),
                m_position(0.0f,0.0f,0.0f,1.0f),
                m_direction(0.0f,1.0f,0.0f,1.0f){;}//centre at origin


    GameObjects(float _v,Vec4 _pos):
                m_size(1.0f),
                m_shapeType(shipType),
                m_velocity(_v),
                m_rot(0.0f),
                m_rotSpd(5.5f),
                m_position(_pos),
                m_direction(0.0f,1.0f,0.0f,1.0f){;}

    GameObjects(float _v,float _size ,Shape _type,Vec4 _dir, Vec4 _pos):
                m_size(_size),
                m_shapeType(_type),
                m_velocity(_v),
                m_rot(0.0f),
                m_rotSpd(0.0f),
                m_position(_pos),
                m_direction(_dir){;}//centre at origin



    GameObjects(Vec4 _dir,Vec4 _pos, float _v, float _rot, float _rotSpd, float _size, Shape _type):
                m_direction(_dir),
                m_position(_pos),
                m_velocity(_v),
                m_rot(_rot),
                m_rotSpd(_rotSpd),
                m_size(_size),
                m_shapeType(_type){;}
protected:

    float m_size;
    float m_velocity;
    float m_rot;
    float m_rotSpd;
    void cycle();
    void outOfScreen();

};
#endif // GAMEOBJECTS_H
