#ifdef WIN32
  #include <Windows.h>
#endif

#if defined (__linux__) || defined (WIN32)
  #include <GL/gl.h>
#endif
#ifdef __APPLE__
  #include <OpenGL/gl.h>
#endif

#include <iostream>
#include <cstdlib>

#include "DrawThings.h"
#include "Camera.h"
#include "SDLOpenGL.h"
#include "CharaControls.h"
#include <iostream>

void followMouse(int _xMouse, int _yMouse)
{

}
