#ifndef DRAWTHINGS_H
#define DRAWTHINGS_H
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
#include <cmath>

class DrawThings
{
public:
    static void draw();
    static void drawAsteroid();
    DrawThings();
    ~DrawThings();

};

#endif // DRAWTHINGS_H
