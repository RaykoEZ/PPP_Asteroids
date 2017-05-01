#ifndef VEC4_H_
#define VEC4_H_
#include <array>

class Vec4
{
public:
    Vec4()=default;
    Vec4(float _x, float _y, float _z, float _w=1.0f) :
        m_x(_x),m_y(_y),m_z(_z),m_w(_w){}

    Vec4 cross(const Vec4 &_r) const;
    void normalize();
    float dot(const Vec4 &_r) const;
    void colourGL() const;
    float length() const;
    float lengthSquared() const;
    void normalGL() const;
    void set(float _x, float _y, float _z, float _w=1.0f);
    void vertexGL() const;

    Vec4 operator -(const Vec4 &_rhs)const;

    Vec4 operator *(float _rhs)const;

    union
    {
        std::array<float,4>  m_openGL={{0.0f,0.0f,0.0f,1.0f}};
        struct
        {
          float m_x;
          float m_y;
          float m_z;
          float m_w;
        };

    };

};

#endif
