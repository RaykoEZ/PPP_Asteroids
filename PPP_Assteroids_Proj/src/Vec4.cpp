#include "Vec4.h"

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


Vec4 Vec4::cross(const Vec4 &_r) const
{
    return Vec4((m_y*_r.m_z)-(m_z*_r.m_y),
                (m_z*_r.m_x)-(m_x*_r.m_z),
                (m_x*_r.m_y)-(m_y*_r.m_x),
            m_w);

}
void Vec4::normalize()
{
    float length = sqrt(m_x*m_x+m_y*m_y+m_z*m_z);
    if (length!=0)
    {
        m_x=m_x/length;
        m_y=m_y/length;
        m_z=m_z/length;
    }

}
float Vec4::dot(const Vec4 &_r) const
{
    float temp = (m_x*_r.m_x)+(m_y*_r.m_y)+(m_z*_r.m_z);
    return temp;

}
void Vec4::colourGL() const
{
    //rgba
    glColor4f(m_x,m_y,m_z,m_w);

}
float Vec4::length() const
{
    return sqrt(m_x*m_x+m_y*m_y+m_z*m_z);

}
float Vec4::lengthSquared() const
{
    return m_x*m_x+m_y*m_y+m_z*m_z;

}
void Vec4::normalGL() const
{
    glNormal3fv(&m_openGL[0]);

}
void Vec4::set(float _x, float _y, float _z, float _w)
{
    m_x=_x;
    m_y=_y;
    m_z=_z;
    m_w=_w;

}
void Vec4::vertexGL() const
{
    glVertex3f(m_x,m_y,m_z);

}

Vec4 Vec4::operator -(const Vec4 &_rhs)const
{
    return Vec4(m_x-_rhs.m_x,
                m_y-_rhs.m_y,
                m_z-_rhs.m_z,
                m_w);
}
//v1*2.0f
Vec4 Vec4::operator *(float _rhs)const
{
    return Vec4(m_x*_rhs,
                m_y*_rhs,
                m_z*_rhs,
                m_w);
}
