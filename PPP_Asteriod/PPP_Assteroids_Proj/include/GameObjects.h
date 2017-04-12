#ifndef GAMEOBJECTS_H
#define GAMEOBJECTS_H
#include "Vec4.h"
#include <cmath>
class GameObjects
{


public:
    virtual ~GameObjects(){;}
    GameObjects():
        m_isDead(false),
        m_isVisible(true),
        m_velocity(1),
        m_rot(0.0f),
        m_position(360.0f,238.0f,0.0f,1.0f),
        m_direction(0.0f,0.0f,0.0f,1.0f){;}//centre at origin


    GameObjects(bool _isDead, bool _isVisible):
                m_isDead(_isDead),
                m_isVisible(_isVisible),
                m_velocity(1),
                m_rot(0.0f),
                m_position(360.0f,238.0f,0.0f,1.0f),
                m_direction(0.0f,0.0f,0.0f,1.0f){;}

    GameObjects(int _v,float _x,float _y,float _z):
                m_isDead(false),
                m_isVisible(true),
                m_velocity(_v),
                m_rot(0.0f),
                m_position(_x,_y,_z,1.0f),
                m_direction(0.0f,0.0f,0.0f,1.0f){;}

    void hideToggle();
    void killToggle();

protected:
    bool m_isDead;
    bool m_isVisible;
    int m_velocity;
    float m_rot;
    Vec4 m_position;
    Vec4 m_direction;

};
#endif // GAMEOBJECTS_H
