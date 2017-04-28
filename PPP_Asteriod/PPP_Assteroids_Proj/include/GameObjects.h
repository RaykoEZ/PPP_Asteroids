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
    typedef void (*shape)(const float _size);
    void hideToggle();
    void killToggle();
    void rotateMe(bool _left,float _rotDeg);
    void forward(shape _type);
    void move(float _step);
    void drawMe(shape _type,float &_x,float &_y, float _rot);

    float getVelo()const{return m_velocity;}

    shape m_shapeType;
    bool m_isDead;
    Vec4 m_position;
    Vec4 m_direction;

    GameObjects():
                m_size(0.75f),
                m_shapeType(shipType),
                m_isDead(false),
                m_isVisible(true),
                m_velocity(1.0f),
                m_rot(0.0f),
                m_rotSpd(5.5f),
                m_position(0.0f,0.0f,0.0f,1.0f),
                m_direction(0.0f,1.0f,0.0f,1.0f){;}//centre at origin

    GameObjects(bool _isDead, bool _isVisible):
                m_size(1.0f),
                m_shapeType(shipType),
                m_isDead(_isDead),
                m_isVisible(_isVisible),
                m_velocity(1.0f),
                m_rot(0.0f),
                m_rotSpd(5.5f),
                m_position(0.0f,0.0f,0.0f,1.0f),
                m_direction(0.0f,1.0f,0.0f,1.0f){;}

    GameObjects(float _v,Vec4 _pos):
                m_size(1.0f),
                m_shapeType(shipType),
                m_isDead(false),
                m_isVisible(true),
                m_velocity(_v),
                m_rot(0.0f),
                m_rotSpd(5.5f),
                m_position(_pos),
                m_direction(0.0f,1.0f,0.0f,1.0f){;}

    GameObjects(float _v,float _size ,shape _type,Vec4 _dir, Vec4 _pos):
                m_size(_size),
                m_shapeType(_type),
                m_isDead(false),
                m_isVisible(true),
                m_velocity(_v),
                m_rot(0.0f),
                m_rotSpd(0.0f),
                m_position(_pos),
                m_direction(_dir){;}//centre at origin



    GameObjects(Vec4 _dir,Vec4 _pos, float _v, float _rot, float _rotSpd, float _size, shape _type):
                m_direction(_dir),
                m_position(_pos),
                m_velocity(_v),
                m_rot(_rot),
                m_rotSpd(_rotSpd),
                m_size(_size),
                m_isVisible(true),
                m_isDead(false),
                m_shapeType(_type){;}
protected:

    float m_size;
    bool m_isVisible;
    float m_velocity;
    float m_rot;
    float m_rotSpd;
    void cycle();
    void outOfScreen();

};
#endif // GAMEOBJECTS_H
