#include "Projectile.h"
#include <iostream>

float Projectile::getRange()
{
    return m_range;
}

void Projectile::setRange(float _range)
{
    m_range=_range;
}

