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

#include "Vec4.h"
#include <cmath>



constexpr float TWO_PI= float(2*M_PI); //6.28318530717958647692   //360
constexpr float PI=float(M_PI); //3.14159265358979323846       //180
constexpr float PI2=float(M_PI/2.0); //1.57079632679489661923      //90
constexpr float PI4=float(M_PI/4.0); //0.785398163397448309615     //45

class Camera
{
  public :
    static void lookAt(Vec4 _eye, Vec4 _look, Vec4 _up);
    static void perspective(float _fovy,float _aspect, float _zNear, float _zFar);
    static float radians(float _deg );

private :
    Camera();
    ~Camera();
    Camera(const Camera &);
    //static void fghCircleTable(double **io_sint, double **io_cost, const int _n  );

};
#endif // CAMERA_H
