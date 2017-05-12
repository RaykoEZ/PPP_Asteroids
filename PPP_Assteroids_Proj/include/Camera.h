#ifndef CAMERA_H
#define CAMERA_H
#ifdef WIN32
  #include <Windows.h> // must be before gl.h include
#endif

#if defined (__linux__) || defined (WIN32)
    #include <GL/gl.h>
#endif
#ifdef __APPLE__
    #include <OpenGL/gl.h>
#endif
#include <cmath>
#include "Vec4.h"

///\file Camera.h
/// \author Chengyan Zhang (Eric)
/// \version 1.0
/// \date Last Revision 06/05/2017 \n

/// Revision History : \n


/// \class Camera
/// \brief Class for setting up camera and perspective view in OpenGL viewport
/// \todo None yet.

///\brief Using PI for maths
constexpr float TWO_PI= float(2*M_PI); //6.28318530717958647692   //360
constexpr float PI=float(M_PI); //3.14159265358979323846       //180
constexpr float PI2=float(M_PI/2.0); //1.57079632679489661923      //90
constexpr float PI4=float(M_PI/4.0); //0.785398163397448309615     //45

class Camera
{
  public :
    ///\brief For initializing view matrix
    /// @param[in] _eye - eye position in Vec4
    /// @param[in] _look - where the eye is looking at in Vec4
    /// @param[in] _up - elevation of camera
    static void lookAt(Vec4 _eye, Vec4 _look, Vec4 _up);

    ///\brief For setting up perspective view
    /// @param[in] _fovy - angle of field of view
    /// @param[in] _aspect - aspect ratio of the screen
    /// @param[in] _zNear - near clipping range
    /// @param[in] _zFar - far clipping range
    static void perspective(float _fovy,float _aspect, float _zNear, float _zFar);

    ///\brief For conversion from degrees to radians
    /// @param[in] _deg - angle to convert
    static float radians(float _deg );

private :
    ///\brief default ctors
    Camera();
    ///@param[in] If multiple camera needed, it is copied in this object
    Camera(const Camera &);
    ~Camera();

};
#endif // CAMERA_H
