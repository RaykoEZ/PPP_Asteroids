#ifndef GAMEOBJECTS_H
#define GAMEOBJECTS_H
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
#include "Vec4.h"

///\file GameObjects.h
/// \author Chengyan Zhang (Eric)
/// \version 1.0
/// \date Last Revision 06/05/2017 \n

/// Revision History : \n

/// \class GameObjects
/// \brief Class for defining a GameObject in general
/// \todo None yet.

///\brief For conversion into degrees
float degree();

///\brief For conversion into radians
float radian();

///\brief For drawing a generic ship
/// @param[in] _size - size modifier
void shipType(const float _size);

///\brief For drawing a generic bullet
/// @param[in] _size - size modifier
void bulletType(const float _size);

///\brief For drawing a generic asteroid
/// @param[in] _size - size modifier
void asteroidType(const float _size);


/// \class GameObjects
/// \brief Class for Storing general methods allowing all GameObjects to move and have basic interactions.
/// \todo None yet.

class GameObjects
{
public:

    ///\brief Function pointer for types of things we draw
    /// @param[in] _size - size modifier
    typedef void (*Shape)(const float _size);

    ///\brief The type of objects defines which function we use to draw
    Shape m_shapeType;

    ///\brief position of object in vector form
    Vec4 m_position;

    ///\brief direction of object in vector form
    Vec4 m_direction;

    ///\brief current velocity
    float m_velocity;

    ///\brief For drawing objects on screen
    /// @param[in] _type - type of object we are drawing calls different glBegin() functions
    /// @param[in] _x - x displacement
    /// @param[in] _y - y displacement
    /// @param[in] _rot - rotation in degrees
    void drawMe(Shape _type,float &_x,float &_y, float _rot);

    ///\brief For modifying direction vector when rotating
    /// @param[in] _left - whether we are roting anti-clockwise
    /// @param[in] _rotDeg - angle size for each rotation
    void rotateMe(bool _left,float _rotDeg);

    ///\brief For calling update function
    /// @param[in] _type - the type of object we are drawing calls different glBegin() functions
    void forward(Shape _type);

    ///\brief For modifying the position vector for movement
    /// @param[in] _step - interval for each move
    void move(float &_step);

    ///\brief For getting the size for this object
    float getSize()const{return m_size;}



    ///\brief default ctor for our player's ship
    GameObjects():
                m_size(0.75f),
                m_shapeType(shipType),
                m_velocity(0.0f),
                m_rot(0.0f),
                m_rotSpd(7.5f),
                m_position(0.0f,0.0f,0.0f,1.0f),
                m_direction(0.0f,1.0f,0.0f,1.0f){;}


    ///\brief ctor for bulllets
    /// @param[in] _v - speed of this object
    /// @param[in] _size - size modifier
    /// @param[in] _type - type of object we should be drawing for this object
    /// @param[in] _dir - direction vector
    /// @param[in] _pos - position vector
    GameObjects(float _v,float _size ,Shape _type,Vec4 _dir, Vec4 _pos):
                m_size(_size),
                m_shapeType(_type),
                m_velocity(_v),
                m_rot(0.0f),
                m_rotSpd(0.0f),
                m_position(_pos),
                m_direction(_dir){;}


    ///\brief ctor for asteroids
    /// @param[in] _dir - direction vector
    /// @param[in] _pos - position vector
    /// @param[in] _v - speed of this object
    /// @param[in] _rot - rotation in degrees
    /// @param[in] _rotSpd - rotation speed of this object
    /// @param[in] _size - size modifier
    /// @param[in] _type - type of object we should be drawing for this object
    GameObjects(Vec4 _dir,Vec4 _pos, float _v, float _rot, float _rotSpd, float _size, Shape _type):
                m_direction(_dir),
                m_position(_pos),
                m_velocity(_v),
                m_rot(_rot),
                m_rotSpd(_rotSpd),
                m_size(_size),
                m_shapeType(_type){;}

    virtual ~GameObjects(){;}

protected:

    ///\brief size modifier
    float m_size;

    ///\brief current angle of rotation in degrees
    float m_rot;

    ///\brief rotation speed
    float m_rotSpd;

    ///\brief For cycling rotation angle when a full turn is made
    void cycle();

    ///\brief For returning objects back into the view volume when they are out of the screen
    void outOfScreen();
    ///\brief maximum position this object can go off the screen;
    float m_clipLimit=20.0f;
};
#endif // GAMEOBJECTS_H
