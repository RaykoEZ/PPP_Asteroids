#include "Mat4.h"
#include <cstring>

#ifdef WIN32
  #include <Windows.h> // must be before gl.h include
#endif

#if defined (__linux__) || defined (WIN32)
  #include <GL/gl.h>
#endif
#ifdef __APPLE__
  #include <OpenGL/gl.h>
#endif

Mat4::Mat4(float _s)
{
    memset(&m_m,0,sizeof(m_m));
    m_00=_s;
    m_11=_s;
    m_22=_s;
    m_33=1.0f;
}
void Mat4::loadModelView() const
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glMultMatrixf(&m_openGL[0]);
}
void Mat4::loadProjection() const
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glMultMatrixf(&m_openGL[0]);
    glMatrixMode(GL_MODELVIEW);
}
void Mat4::identity()
{
    memset(&m_m,0,sizeof(m_m));
    m_00=1.0f;
    m_11=1.0f;
    m_22=1.0f;
    m_33=1.0f;
}
