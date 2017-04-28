#include "Projectile.h"
#include <iostream>

float Projectile::getRange()const
{
    return m_range;
}

void Projectile::setRange(float _range)
{
    m_range=_range;
}


void Projectile::shoot()
{
    //std::cout<<"Shooting"<<'\n';
    move(m_velocity);
    forward(bulletType);
    rangeDecay();
}

void Projectile::rangeDecay()
{

    m_range-=m_velocity;


}

bool Projectile::checkDecay()
{
    if(m_range<=0.0f)
    {
        return true;
    }
    return false;
}
