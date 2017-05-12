#ifndef PROJECTILE_H
#define PROJECTILE_H
#include <iostream>
#include "GameObjects.h"

///\file Projectile.h
/// \author Chengyan Zhang (Eric)
/// \version 1.0
/// \date Last Revision 06/05/2017 \n

/// Revision History : \n


/// \class Projectile
/// \brief Class for Storing bullet range and functions to modify it.
/// \todo None yet.

class Projectile : public GameObjects
{
public:
    ///\brief default ctor
    Projectile():
        m_range(35.0f){;}

    ///\brief ctor for constructing a bullet object
    /// @param[in] _dir - direction vector
    /// @param[in] _pos - position vector
    Projectile(Vec4 _dir,Vec4 _pos):
               GameObjects(1.0f,0.5f,bulletType,_dir,_pos),
               m_range(35.0f)
               {
                //std::cout<<'\n'<<"Bullet Creation"<<'\n';
               }

    ~Projectile()
    {
        //std::cout<<"Bullet destruction"<<'\n';
    }

    ///\brief For getting the range of this object
    /// @param[in] _range - the range value to be set
    void setRange(const float _range);

    ///\brief For set range for this object
    float getRange()const{return m_range;}

    ///\brief For moving the bullet as a GameObject when it's shot out
    void shoot();

    ///\brief For decrementing the range when this bullet travels
    void rangeDecay();

    ///\brief For checking whether this object is out of its range
    bool checkDecay();
private:

    ///\brief the travel range for the bullet
    float m_range;

};
#endif // PROJECTILE_H
