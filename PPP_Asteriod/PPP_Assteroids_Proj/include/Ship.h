#ifndef SHIP_H
#define SHIP_H
#include "GameObjects.h"
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
class Ship : public GameObjects
{
public:

    Ship():
        m_fireRate(1){;}

    ~Ship();
    void drawMe(int _x, int _y, GLfloat _rot);
    //NOTE: SDL_MOUSEMOTION y position = -z position in this created space
    void followMouse(int _xMouse, int _yMouse);
private:
    int m_fireRate;

};

#endif // SHIP_H
