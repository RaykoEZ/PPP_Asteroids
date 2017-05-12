#ifndef VEC4_H_
#define VEC4_H_
#include <array>

///\file Vec4.h
class Vec4
{
public:
    ///\brief default ctor
    Vec4()=default;

    ///brief ctor for instantiation with values
    /// @param[in] _x - x value
    /// @param[in] _y - y value
    /// @param[in] _z - z value
    /// @param[in] _w - w value always set to 1.0f
    Vec4(float _x, float _y, float _z, float _w=1.0f) :
        m_x(_x),m_y(_y),m_z(_z),m_w(_w){}

    ///\brief return cross product
    /// @param[in] _r - the other operand
    Vec4 cross(const Vec4 &_r) const;

    ///\brief normalize this Vec4
    void normalize();

    ///\brief return dot product
    /// @param[in] _r - the other operand
    float dot(const Vec4 &_r) const;

    ///\brief set colour
    void colourGL() const;

    ///\brief return magnitude of the Vec4
    float length() const;

    ///\brief return the square of magnitude
    float lengthSquared() const;

    ///\brief turn to their normal vector
    void normalGL() const;

    ///\brief set values to this Vec4
    /// @param[in] _x - x value
    /// @param[in] _y - y value
    /// @param[in] _z - z value
    /// @param[in] _w - identify as vector or point
    void set(float _x, float _y, float _z, float _w=1.0f);

    ///\brief sets this Vec4 to a glVertex3f
    void vertexGL() const;

    ///\brief operator "-" for vector maths
    Vec4 operator -(const Vec4 &_rhs)const;

    ///\brief operator "*" for mulyiplying scalar against vector
    Vec4 operator *(float _rhs)const;

    union
    {
        ///\brief array of 4 values x,y,z,w
        std::array<float,4>  m_openGL={{0.0f,0.0f,0.0f,1.0f}};
        struct
        {
          ///\brief values stored in this object
          float m_x;
          float m_y;
          float m_z;
          float m_w;
        };

    };

};

#endif
