#include <iostream>
#include "Projectile.h"

///\file Projectile.cpp

void Projectile::setRange(const float _range)
{
    m_range=_range;
}

//-----------------------------------------------

void Projectile::shoot()
{
    //moving bullet
    move(m_velocity);
    forward(bulletType);
    //check whether this object is out of travel range
    rangeDecay();
}

//-----------------------------------------------

void Projectile::rangeDecay()
{

    //decrement range
    m_range-=m_velocity;

}

//----------------------------------------------

bool Projectile::checkDecay()
{
    //check whether range has ran out
    if(m_range<=0.0f)
    {
        return true;
    }
    return false;
}
